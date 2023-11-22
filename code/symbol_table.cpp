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

int Type::push_type(VarTypes core_type, int offset, int size, Aux * aux) {
    InnerType *it = new InnerType(core_type, offset, size);
    switch(core_type) {
        case STRUCT:
            it->set_aux(aux->sste);
            this->str = aux->sste->name;
            break;
        case ENUM:
            it->set_aux(aux->este);
            this->str = aux->este->name;
            break;
        case CART:
            it->set_aux(aux->cart);
            this->str = "tuple<";
            for (int i = 0; i < aux->cart->size(); i++) {
                if (i) this->str += ", ";
                this->str += (*aux->cart)[i]->str;
            }
            this->str += ">";
            break;
        case GEN:
            it->set_aux(aux->gste, aux->types);
            this->str = aux->gste->name;
            this->str += "<";
            for (int i = 0; i < aux->types->size(); i++) {
                if (i) this->str += ", ";
                auto it = (*aux->types)[i];
                if (it->is_int) {
                    this->str += to_string(it->lit_int);
                } else {
                    this->str += it->type->str;
                }
            }
            break;
        case BUF:
            this->str += "[]";
            break;
        case REF:
            this->str += "*";
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

int typecmp(InnerType *t1, InnerType *t2, bool ignore_gen) {
    while (t1 && t2) {
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
                // Type nt1;
                // nt1.head = it1;
                // Type nt2;
                // nt2.head = it2;
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
                    return v1i->lit_int != v2i->lit_int;
                } else {
                    return typecmp(v1i->type, v2i->type);
                }
            }
        } else if (t1->core_type == BUF || t1->core_type == GEN) {
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


Var::Var(string name, Type *type) {
    this->name = name;
    this->type = type;
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
}

Type *Struct::make_struct_type() {
    Type *t = new Type();

    (t->head = new InnerType(STRUCT, 0, 0))->set_aux(this);
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

Function * ForgeSymbolTable::lookup(Type *t1, Type *t2) {
    FunctionSymbolTable *f = &this->inner;
    for (auto i : f->entries) {
        Type *t = get_param_type(i);
        if (!typecmp(t, t1, true) && !typecmp(i->return_type, t2, true)) {
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
