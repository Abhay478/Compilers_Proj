#include "semantic.hpp"
using namespace std;


//! note: All symbol table lookups should be preceded with a lookup to the global symbol table. 
//! this means we don't have to put pointers to the thing everywhere. Phew.

/*******************
 * TYPE
********************/  
// Type * make_type() {
//     Type * t = (Type *)calloc(1, sizeof(Type));
//     return t;
// }
// InnerType::InnerType() {
//     this->core_type = VOID;
//     this->offset = 0;
//     this->size = 0;
//     this->aux = NULL;
//     this->next = NULL;
// }

AuxSSTE::AuxSSTE(StructSymbolTableEntry * sste) {
    this->sste = sste;
}

AuxESTE::AuxESTE(EnumSymbolTableEntry * este) {
    this->este = este;
}

AuxCART::AuxCART(deque<InnerType *> cart) {
    this->cart = cart;
}


InnerType::InnerType(VarTypes core_type, int offset, int size) {
    this->core_type = core_type;
    this->offset = offset;
    this->size = size;
    this->next = NULL;
}


int Type::push_type(VarTypes core_type, int offset, int size, Aux * aux) {
    InnerType * it = new InnerType(core_type, offset, size);
    it->aux = aux;
    it->next = this->head;
    this->head = it;
    return 0;
}

int typecmp(Type * t1, Type * t2) {
    InnerType * current1 = t1->head;
    InnerType * current2 = t2->head;
    while (current1 && current2) {
        if (current1->core_type != current2->core_type) {
            return 1;
        }
        if(current1->core_type == STRUCT || current1->core_type == ENUM) {
            if(current1->aux != current2->aux) {
                return 1;
            } // This is fine, as there is only one symbol table entry for each struct or enum in the global table.
        }

        if(current1->core_type == CART) {
            if(current1->size != current2->size) {
                return 1;
            }
            for(int i = 0; i < current1->size; i++) {
                InnerType * it1 = ((AuxCART *)current1->aux)->cart[i];
                InnerType * it2 = ((AuxCART *)current2->aux)->cart[i];
                Type nt1; nt1.head = it1;
                Type nt2; nt2.head = it2;
                if(typecmp(&nt1, &nt2)) { // Bhupendra Jogi.
                    return 1;
                }
            }
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 || current2) {
        return 1;
    }
    return 0;
}

/*******************
 * VAR
********************/

// VarSymbolTableEntry * make_vste(char * name, void * value, Type * type, int offset, int size, void * aux) {
//     VarSymbolTableEntry * vste = (VarSymbolTableEntry *)malloc(sizeof(VarSymbolTableEntry));
//     vste->name = name;
//     vste->type = type;
//     return vste;
// }

VarSymbolTableEntry::VarSymbolTableEntry(string name, Type * type) {
    this->name = name;
    this->type = type;
}

int VarSymbolTable::insert(VarSymbolTableEntry * vste) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == vste->name) {
            // Same type fine.
            if(!typecmp(this->entries[i]->type, vste->type)) {
                return 0;
            }
            return 1;
        }
    }
    this->entries.push_back(vste);
    
    return 0;
}

VarSymbolTableEntry * VarSymbolTable::lookup(string name) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == name) {
            return this->entries[i];
        }
    }
    return NULL;
}

// VarSymbolTable * make_vst() {
//     VarSymbolTable * st = (VarSymbolTable *)malloc(sizeof(VarSymbolTable));
//     st->size = 0;
//     st->capacity = 69;
//     st->entries = (VarSymbolTableEntry **)malloc(st->capacity * sizeof(VarSymbolTableEntry *));
//     return st;
// }   

// VarSymbolTable::VarSymbolTable() {
//     this->size = 0;
//     this->capacity = 69;
//     this->entries = vector<VarSymbolTableEntry *>();
// }

/*******************
 * FUNC
********************/

/// @brief Generated by the function prototype, modified by the function definition. 
/// That's why the ScopeTree is NULL. 
FunctionSymbolTableEntry * make_fste(char * name, int numParams, VarSymbolTable * params) {
    FunctionSymbolTableEntry * fste = (FunctionSymbolTableEntry *)malloc(sizeof(FunctionSymbolTableEntry));
    fste->name = name;
    fste->numParams = numParams;
    fste->params = params;
    fste->locals = NULL;
    return fste;
}

FunctionSymbolTableEntry::FunctionSymbolTableEntry(char * name, int numParams, VarSymbolTable * params) {
    this->name = name;
    this->numParams = numParams;
    this->params = params;
    this->locals = NULL;
}

int FunctionSymbolTable::insert(FunctionSymbolTableEntry * fste) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == fste->name) {
            return 1;
        }
    }
    this->entries.push_back(fste);
    
    return 0;
}

FunctionSymbolTableEntry * FunctionSymbolTable::lookup(string name) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == name) {
            return this->entries[i];
        }
    }
    return NULL;
}

void Scope::add_child(Scope * child) {
    this->children.push_back(child);
    child->parent = this;
}

/// @brief Provide the current scope and the current function.
VarSymbolTableEntry * scoped_lookup(FunctionSymbolTableEntry * func, Scope * s, string name) {
    VarSymbolTableEntry * vste = func->params->lookup(name);
    if(vste) {
        return vste;
    }
    Scope * current = s;
    while (current) {
        vste = current->vars->lookup(name);
        if (vste) {
            return vste;
        }
        current = current->parent;
    }
    return NULL;
}

/*******************
 * STRUCT
********************/

Var::Var(string name, Type * type, int offset, int size) {
    this->name = name;
    this->type = type;
    this->offset = offset;
    this->size = size;

}

StructSymbolTableEntry::StructSymbolTableEntry(string name, deque<Var> fields) {
    this->name = name;
    this->fields = fields;
}

Type * StructSymbolTableEntry::make_struct_type() {
    Type * t = new Type();

    t->head = new InnerType(STRUCT, 0, 0);
    ((AuxSSTE *)t->head->aux)->sste = this;
    return t;
}

int StructSymbolTable::insert(StructSymbolTableEntry * sste) {
    for (int i = 0; i < this->entries.size(); i++) {
        if (this->entries[i]->name == sste->name) {
            return 1;
        }
    }

    this->entries.push_back(sste);
    
    return 0;
}

StructSymbolTableEntry * StructSymbolTable::lookup(string name) {
    for (auto i: this->entries) {
        if (i->name == name) {
            return i;
        }
    }
    return NULL;
}

/*******************
 * ENUM
********************/

EnumSymbolTableEntry::EnumSymbolTableEntry(string name, deque<string> fields) {
    this->name = name;
    this->fields = fields;
}

int EnumSymbolTable::insert(EnumSymbolTableEntry * este) {
    for (auto i: this->entries) {
        if (i->name == este->name) {
            return 1;
        }
    }
    
    this->entries.push_back(este);
    return 0;
}

EnumSymbolTableEntry * EnumSymbolTable::lookup(string name) {
    for (auto i: this->entries) {
        if (i->name == name) {
            return i;
        }
    }
    return NULL;
}

/*******************
 * FORGE
********************/

int ForgeSymbolTable::insert(FunctionSymbolTableEntry * fste) {
    return this->inner->insert(fste);
}

Type * get_param_type(FunctionSymbolTableEntry * f) {
    VarSymbolTable * params = f->params;
    if(params->entries.size() == 1) {
        // Only one parameter, just return it's type.
        return params->entries[0]->type;
    }

    Type * t = new Type();
    t->head = new InnerType(CART, 0, params->entries.size());

    for(auto i: params->entries) {
        ((AuxCART *)t->head->aux)->cart.push_back(i->type->head);
    }

    return t;
}

FunctionSymbolTableEntry * ForgeSymbolTable::lookup(Type * t1, Type * t2) {
    FunctionSymbolTable * f = this->inner;
    for(auto i: f->entries) {
        Type * t = get_param_type(i);
        if((!typecmp(t, t1) && !typecmp(i->return_type, t2)) || (!typecmp(t, t2) && !typecmp(i->return_type, t1))) {
            return i; // A forge !
        }
    }
    return NULL;
}

/*******************
 * CLAIM
********************/

// ClaimSymbolTableEntry * make_claim_ste(Type * type, Archetypes archetype) {
//     ClaimSymbolTableEntry * cste = (ClaimSymbolTableEntry *)malloc(sizeof(ClaimSymbolTableEntry));
//     cste->type = type;
//     cste->archetype = archetype;
//     return cste;
// }
 
ClaimSymbolTableEntry::ClaimSymbolTableEntry(Type * type, Archetypes archetype) {
    this->type = type;
    this->archetype = archetype;
}

int ClaimSymbolTable::insert(ClaimSymbolTableEntry * cste) {
    for (auto i: this->entries) {
        if (!typecmp(i->type, cste->type) && i->archetype == cste->archetype) {
            return 1;
        }
    }
    this->entries.push_back(cste);
    
    return 0;
}

ClaimSymbolTableEntry * ClaimSymbolTable::lookup(Type * type, Archetypes archetype) {
    // for (int i = 0; i < cst->size; i++) {
    //     if(!typecmp(cst->entries[i]->type, type) && cst->entries[i]->archetype == archetype) {
    //         return cst->entries[i];
    //     }
    // }
    for (auto i: this->entries) {
        if(!typecmp(i->type, type) && i->archetype == archetype) {
            return i;
        }
    }
    return NULL;
}