//! note: All symbol table lookups should be preceded with a lookup to the global symbol table.
#include "semantic.hpp"
using namespace std;

//! this means we don't have to put pointers to the thing everywhere. Phew.

/*******************
 * TYPE
 ********************/

InnerType::InnerType(VarTypes core_type, int offset, int size) {
    this->core_type = core_type;
    this->offset = offset;
    this->size = size;
    this->next = NULL;
}

string InnerType::repr_cpp() {
    switch (this->core_type) {
        case VOID:
        case INT:
        case FLOAT:
        case BOOL:
        case CHAR:
            return get_pdt_str(this->pdt);
        case STR:
            return "std::string";
        case BUF:
            return "std::vector<" + this->next->repr_cpp() + ">";
        case REF:
            return this->next->repr_cpp() + "*";
        case GEN: {
            std::string s = this->gste->name + "<";
            for (int i = 0; i < this->types->size(); i++) {
                auto it = (*this->types)[i];
                if (i) {
                    s += ", ";
                }
                if (it->is_int) {
                    s += to_string(it->lit_int);
                } else {
                    s += it->type->repr_cpp();
                }
            }
            s += ">";
            return s;
        }
        case STRUCT:
            return this->sste->name;
        case ENUM:
            return this->este->name;
        case CART: {
            std::string s = "std::tuple<";
            for (int i = 0; i < this->cart->size(); i++) {
                auto it = (*this->cart)[i];
                if (i) {
                    s += ", ";
                }
                s += it->repr_cpp();
            }
            s += ">";
            return s;
        }
        case PLACEHOLDER:
            return "__placeholder__";
        default:
            return "unreachable";
    }
}

string Type::repr_cpp() {
    return this->head->repr_cpp();
}

int Type::push_type(VarTypes core_type, int offset, int size, Aux * aux) {
    InnerType *it = new InnerType(core_type, offset, size);
    switch(core_type) {
        case STRUCT:
            it->set_aux(aux->sste);
            break;
        case ENUM:
            it->set_aux(aux->este);
            break;
        case CART:
            it->set_aux(aux->cart);
            break;
        case GEN:
            it->set_aux(aux->gste, aux->types);
            break;
        case BUF:
            break;
        case REF:
            break;
        default: break;
    }
    it->next = this->head;
    this->head = it;
    return 0;
}

VarTypes Type::core() {
    return this->head->core_type;
}

Type *Type::pop_type() {
    Type *t = new Type();
    t->head = this->head->next;
    return t;
}

// find the first placeholder in t
// and replace it with repl
// deep copy
InnerType *replace_placeholder(InnerType *t, GenericInner *repl) {
    InnerType *ret = NULL;
    switch (t->core_type) {
        case PLACEHOLDER:
            return repl->type->head;
        case BUF:
        case REF:
            ret = new InnerType(t->core_type, t->offset, t->size);
            ret->next = replace_placeholder(t->next, repl);
            return ret;
        case GEN: {
            ret = new InnerType(t->core_type, t->offset, t->size);
            auto inners = new vector<GenericInner *>();
            for (int i = 0; i < t->types->size(); i++) {
                auto it = (*t->types)[i];
                GenericInner *inner;
                if (it->is_int) {
                    if (it->lit_int == -1) {
                        // placeholder
                        inner = repl;
                    } else {
                        inner = new GenericInner(it->lit_int);
                    }
                } else {
                    auto rep = replace_placeholder(it->type->head, repl);
                    auto type = new Type();
                    type->head = rep;
                    inner = new GenericInner(type);
                }
                inners->push_back(inner);
            }
            ret->set_aux(t->gste, inners);
            return ret;
        }
        case CART: {
            ret = new InnerType(t->core_type, t->offset, t->size);
            auto types = new vector<Type *>();
            for (int i = 0; i < t->cart->size(); i++) {
                auto it = (*t->cart)[i];
                auto type = new Type();
                type->head = replace_placeholder(it->head, repl);
                types->push_back(type);
            }
            ret->set_aux(types);
            return ret;
        }
        default:
            // remaining types cannot have placeholders
            // so just return the original type
            return t;
    }
}

// if t1 has a placeholder, get the matching type from t2
// assumes t1 and t2 match in all other ways
// if no placeholder in t1, return NULL
GenericInner *placeholder_equiv(InnerType *t1, InnerType *t2) {
    while (t1 && t2) {
        if (t1->core_type == PLACEHOLDER) {
            auto ret = new Type();
            ret->head = t2;
            return new GenericInner(ret);
        }

        if (t1->core_type == CART) {
            for (int i = 0; i < t1->size; i++) {
                Type * it1 = (*t1->cart)[i];
                Type * it2 = (*t2->cart)[i];
                auto ret = placeholder_equiv(it1->head, it2->head);
                if (ret) {
                    return ret;
                }
            }
            return NULL;
        } else if (t1->core_type == GEN) {
            auto v1 = t1->types;
            auto v2 = t2->types;

            for (int i = 0; i < v1->size(); i++) {
                auto v1i = (*v1)[i];
                auto v2i = (*v2)[i];
                if (v1i->is_int) {
                    if (v1i->lit_int == -1) {
                        // placeholder
                        return new GenericInner(v2i->lit_int);
                    }
                    continue;
                }
                auto ret = placeholder_equiv(v1i->type->head, v2i->type->head);
                if (ret) {
                    return ret;
                }
            }
            return NULL;
        } else if (t1->core_type == BUF || t1->core_type == GEN) {
            t1 = t1->next;
            t2 = t2->next;
        } else {
            // All other types are primitive
            return NULL;
        }
    }
    return NULL;
}

int typecmp(InnerType *t1, InnerType *t2, bool ignore_gen) {
    while (t1 && t2) {
        if (t1->core_type == PLACEHOLDER || t2->core_type == PLACEHOLDER) {
            return 0;
        }
        if (t1->core_type != t2->core_type) {
            return 1;
        }

        if (t1->core_type == STRUCT) {
            // Fine, as there is only one symbol table entry for each struct.
            return t1->sste != t2->sste;
        } else if (t1->core_type == ENUM) {
            // Fine, as there is only one symbol table entry for each enum.
            return t1->este != t2->este;
        } else if (t1->core_type == CART) {
            if (t1->size != t2->size) {
                return 1;
            }
            for (int i = 0; i < t1->size; i++) {
                Type * it1 = (*t1->cart)[i];
                Type * it2 = (*t2->cart)[i];
                if (typecmp(it1, it2)) { // Bhupendra Jogi.
                    return 1;
                }
            }
            return 0;
        } else if (t1->core_type == GEN) {
            if (t1->gste != t2->gste) {
                return 1;
            }
            if (ignore_gen) {
                return 0;
            }
            auto v1 = t1->types;
            auto v2 = t2->types;

            for (int i = 0; i < v1->size(); i++) {
                auto v1i = (*v1)[i];
                auto v2i = (*v2)[i];
                if (v1i->is_int) {
                    if(v1i->lit_int == -1 || v2i->lit_int == -1) {
                        // placeholder
                        continue;
                    }
                    if(v1i->lit_int != v2i->lit_int) return 1;
                } else {
                    if(typecmp(v1i->type, v2i->type)) return 1;
                }
            }
            return 0;
        } else if (t1->core_type == BUF) {
            t1 = t1->next;
            t2 = t2->next;
        } else {
            // All other types are primitive
            return 0;
        }
    }
    if (t1 || t2) {
        return 1;
    }
    return 0;
}

int typecmp(InnerType *t1, InnerType *t2) {
    return typecmp(t1, t2, false);
}

int typecmp(Type *t1, Type *t2, bool ignore_gen) {
    if (!t1 || !t2) return 0;
    return typecmp(t1->head, t2->head, ignore_gen);
}

int typecmp(Type *t1, Type *t2) {
    if (!t1 || !t2) return 0;
    return typecmp(t1->head, t2->head, false);
}

Expr::Expr(Type *t, bool is_lvalue) {
    this->head = t->head;
    this->is_lvalue = is_lvalue;
}

/*******************
 * VAR
 ********************/


int varcount = 0;
Var::Var(string name, Type *type) {
    this->name = name;
    this->type = type;
    this->varno = varcount++;
}

std::string Var::repr_cpp() {
    return "v" + to_string(this->varno) + "_" + this->name;
}

int VarSymbolTable::insert(Var *vste) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == vste->name) {
            return 1;
        }
    }
    this->entries.push_back(vste);

    return 0;
}

Var *VarSymbolTable::lookup(string name) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == name) {
            return this->entries[i];
        }
    }
    return NULL;
}

/*******************
 * FUNC
 ********************/

Function::Function(string name, VarSymbolTable *params, Type *return_type) {
    this->name = name;
    this->params = params;
    this->return_type = return_type;
}

int FunctionSymbolTable::insert(Function *fste) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == fste->name) {
            return 1;
        }
    }
    this->entries.push_back(fste);

    return 0;
}

Function *FunctionSymbolTable::lookup(string name) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == name) {
            return this->entries[i];
        }
    }
    return NULL;
}

// if return type has a placeholder, get the matching type from args
Type * Function::get_return_type(std::vector<Type *> * args, Type * ret_type) {
    GenericInner * repl = NULL;
    for (int i = 0; i < args->size(); i++) {
        auto arg = (*args)[i]->head;
        auto equiv = placeholder_equiv(this->params->entries[i]->type->head, arg);
        if (equiv) {
            // arg has placeholder
            if (repl) {
                // multiple args have placeholders, so they must match
                if (repl->is_int && equiv->is_int) {
                    if (repl->lit_int != equiv->lit_int) {
                        // corresponding types don't match
                        return NULL;
                    }
                } else if (repl->is_int || equiv->is_int) {
                    // one is a placeholder and the other is not
                    return NULL;
                } else if (typecmp(repl->type, equiv->type)) {
                    // both are types, but they don't match
                    return NULL;
                }
            }
            repl = equiv;
        }
    }
    auto ret = placeholder_equiv(this->return_type->head, this->return_type->head);
    if (!ret) {
        // no placeholder in return type
        return this->return_type;
    }
    if (!repl) {
        // no args had placeholders
        // check if return type has a placeholder
        if (ret_type == NULL) {
            // no return type given
            return NULL;
        }
        auto ret = placeholder_equiv(this->return_type->head, ret_type->head);
        if (ret) {
            // return type has placeholder
            return ret_type;
        }
    }
    // replace placeholder in return type with type from args
    auto t = replace_placeholder(this->return_type->head, repl);
    auto ty = new Type();
    ty->head = t;
    return ty;
}

Type * Function::get_return_type(std::vector<Expr *> * args, Type *ret_type) {
    // convert args to vector of types
    auto types = new vector<Type *>();
    for (auto i : *args) {
        auto t = new Type();
        t->head = i->head;
        types->push_back(t);
    }
    return this->get_return_type(types, ret_type);
}

static std::string repr(GenericInner *inner) {
    if (inner->is_int) {
        return "<" + to_string(inner->lit_int) + ">";
    } else {
        return "<" + inner->type->repr_cpp() + ">";
    }
}

std::string Function::get_gen_arg(std::vector<Expr *> * args, Type *ret_type) {
    auto placeholder = placeholder_equiv(this->return_type->head, ret_type->head);
    if (placeholder) {
        return repr(placeholder);
    }
    for (int i = 0; i < args->size(); i++) {
        auto arg = (*args)[i]->head;
        auto equiv = placeholder_equiv(this->params->entries[i]->type->head, arg);
        if (equiv) {
            return repr(equiv);
        }
    }
    return "";
}

std::string Function::repr_cpp() {
    return "f_" + this->name;
}

Var * Scope::lookup(string name) {
    Var * vste = NULL;
    Scope * current = this;
    while(current && !vste) {
        vste = current->vars->lookup(name);
        current = current->parent;
    }
    return vste;
}

/*******************
 * STRUCT
 ********************/

Struct::Struct(string name, vector<Var *> fields) {
    this->name = name;
    this->fields = fields;
    this->methods = new FunctionSymbolTable();
}

Type *Struct::make_struct_type() {
    Type *t = new Type();

    t->head = new InnerType(STRUCT, 0, 0);
    t->head->set_aux(this);
    return t;
}

int StructSymbolTable::insert(Struct *sste) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == sste->name) {
            return 1;
        }
    }

    this->entries.push_back(sste);

    return 0;
}

Struct *StructSymbolTable::lookup(string name) {
    for (auto i : this->entries) {
        if (i->name == name) {
            return i;
        }
    }
    return NULL;
}

Var *Struct::fieldLookup(string field_name) {
    for (auto i : this->fields) {
        if (i->name == field_name) {
            return i;
        }
    }
    return NULL;
}
/*******************
 * ENUM
 ********************/

Enum::Enum(string name, vector<string> fields) {
    this->name = name;
    this->fields = fields;
}

int EnumSymbolTable::insert(Enum *este) {
    for (auto i : this->entries) {
        if (i->name == este->name) {
            return 1;
        }
    }

    this->entries.push_back(este);
    return 0;
}

Enum *EnumSymbolTable::lookup(string name) {
    for (auto i : this->entries) {
        if (i->name == name) {
            return i;
        }
    }
    return NULL;
}

/*******************
 * FORGE
 ********************/

int ForgeSymbolTable::insert(Function *fste) {
    for (auto i : this->inner.entries) {
        if (!typecmp(get_param_type(i), get_param_type(fste), true) && !typecmp(i->return_type, fste->return_type, true)) {
            return 1;
        }
    }
    this->inner.entries.push_back(fste);
    return 0;
}

Type *get_param_type(Function *f) {
    VarSymbolTable *params = f->params;
    if (params->entries.size() == 1) {
        // Only one parameter, just return it's type.
        return params->entries[0]->type;
    }

    Type *t = new Type();
    auto cart = new vector<Type *>();
    for (auto i : params->entries) {
        cart->push_back(i->type);
    }
    t->push_type(CART, 0, params->entries.size(), new Aux(cart));


    return t;
}

// return a forge to convert t1 to t2
Function * ForgeSymbolTable::lookup(Type *t1, Type *t2) {
    FunctionSymbolTable *f = &this->inner;
    for (auto i : f->entries) {
        Type *t = get_param_type(i);
        if (!typecmp(t, t1, true) && !typecmp(i->return_type, t2, true)) {
            auto pl1 = placeholder_equiv(t->head, t1->head);
            auto pl2 = placeholder_equiv(i->return_type->head, t2->head);
            if (pl1 && pl2) {
                // both had placeholders, so corresponding types must match
                if (pl1->is_int && pl2->is_int) {
                    if (pl1->lit_int != pl2->lit_int) {
                        // corresponding types don't match
                        continue;
                    }
                } else if (pl1->is_int || pl2->is_int) {
                    // one is a placeholder and the other is not
                    continue;
                } else if (typecmp(pl1->type->head, pl2->type->head)) {
                    // both are types, but they don't match
                    continue;
                }
            }
            return i; // A forge !
        }
    }
    return NULL;
}

/*******************
 * CLAIM
 ********************/

Claim::Claim(Type *type, Archetypes archetype) {
    this->type = type;
    this->archetype = archetype;
}

int ClaimSymbolTable::insert(Claim *cste) {
    for (auto i : this->entries) {
        if (!typecmp(i->type, cste->type, true) && i->archetype == cste->archetype) {
            return 1;
        }
    }
    this->entries.push_back(cste);

    return 0;
}

Claim *ClaimSymbolTable::lookup(Type *type, Archetypes archetype) {
    if(type->core() == CART && (archetype == GROUP || archetype == RING)) {
        auto cart = type->head->cart;
        for(auto it : *cart) {
            auto c = this->lookup(it, archetype);
            if(!c) {
                return NULL;
            }
        }
        return new Claim(type, archetype);
    }
    for (auto i : this->entries) {
        if (!typecmp(i->type, type, true) && i->archetype == archetype) {
            return i;
        }
    }
    return NULL;
}

/*******************
 * LIB
 ********************/

int GenSymbolTable::insert(Generic *lste) {
    for (auto i : this->entries) {
        if (i->name == lste->name) {
            return 1;
        }
    }
    this->entries.push_back(lste);

    return 0;
}

Generic * GenSymbolTable::lookup(string name) {
    for (auto i : this->entries) {
        if (i->name == name) {
            return i;
        }
    }
    return NULL;
}

GenericArg::GenericArg() {
    this->is_int = true;
}

GenericArg::GenericArg(Archetypes archetype) {
    this->is_int = false;
    this->archetype = archetype;
}
