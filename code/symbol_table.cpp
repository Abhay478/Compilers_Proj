#include "semantic.hpp"
using namespace std;

//! note: All symbol table lookups should be preceded with a lookup to the global symbol table.
//! this means we don't have to put pointers to the thing everywhere. Phew.

/*******************
 * TYPE
 ********************/

AuxSSTE::AuxSSTE(Struct *sste) {
    this->sste = sste;
}

AuxESTE::AuxESTE(Enum *este) {
    this->este = este;
}

AuxCART::AuxCART(vector<InnerType *> cart) {
    this->cart = cart;
}

InnerType::InnerType(VarTypes core_type, int offset, int size) {
    this->core_type = core_type;
    this->offset = offset;
    this->size = size;
    this->next = NULL;
}

int Type::push_type(VarTypes core_type, int offset, int size, Aux *aux) {
    InnerType *it = new InnerType(core_type, offset, size);
    it->aux = aux;
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

int typecmp(InnerType *t1, InnerType *t2) {
    while (t1 && t2) {
        if (t1->core_type != t2->core_type) {
            // printf("core type mismatch: %d, %d\n", t1->core_type, t2->core_type);
            return 1;
        }
        if (t1->core_type == STRUCT) {
            if (isste(t1) != isste(t2)) {
                // printf("aux mismatch: %s, %s.\n", ((AuxSSTE *)t1->aux)->sste->name.c_str(), ((AuxSSTE *)t2->aux)->sste->name.c_str());
                return 1;
            } // This is fine, as there is only one symbol table entry for each struct or enum in the global table.
        }

        if (t1->core_type == ENUM) {
            if (ieste(t1) != ieste(t2)) {
                // printf("aux mismatch: %s, %s.\n", ((AuxESTE *)t1->aux)->este->name.c_str(), ((AuxESTE *)t2->aux)->este->name.c_str());
                // printf("aux mismatch: %p, %p.\n", t1->aux, t2->aux);
                return 1;
            } // This is fine, as there is only one symbol table entry for each struct or enum in the global table.
        }

        if (t1->core_type == CART) {
            if (t1->size != t2->size) {
                return 1;
            }
            for (int i = 0; i < t1->size; i++) {
                InnerType *it1 = icart(t1)[i];
                InnerType *it2 = icart(t2)[i];
                Type nt1;
                nt1.head = it1;
                Type nt2;
                nt2.head = it2;
                if (typecmp(&nt1, &nt2)) { // Bhupendra Jogi.
                    return 1;
                }
            }
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t1 || t2) {
        return 1;
    }
    return 0;
}

int typecmp(Type *t1, Type *t2) {
    return typecmp(t1->head, t2->head);
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

    t->head = new InnerType(STRUCT, 0, 0);
    sste(t) = this;
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
        if (!typecmp(get_param_type(i), get_param_type(fste)) && !typecmp(i->return_type, fste->return_type)) {
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
    auto cart = new vector<InnerType *>();
    for (auto i : params->entries) {
        cart->push_back(i->type->head);
    }
    t->push_type(CART, 0, params->entries.size(), new AuxCART(*cart));


    return t;
}

Function * ForgeSymbolTable::lookup(Type *t1, Type *t2) {
    FunctionSymbolTable *f = &this->inner;
    for (auto i : f->entries) {
        Type *t = get_param_type(i);
        if (!typecmp(t, t1) && !typecmp(i->return_type, t2)) {
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
        if (!typecmp(i->type, cste->type) && i->archetype == cste->archetype) {
            return 1;
        }
    }
    this->entries.push_back(cste);

    return 0;
}

Claim *ClaimSymbolTable::lookup(Type *type, Archetypes archetype) {
    for (auto i : this->entries) {
        if (!typecmp(i->type, type) && i->archetype == archetype) {
            return i;
        }
    }
    return NULL;
}
