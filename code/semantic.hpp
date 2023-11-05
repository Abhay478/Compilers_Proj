#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <deque>

#ifndef _SEMANTIC_H
#define _SEMANTIC_H
/***********************************************
 * Struct declarations.
************************************************/

typedef struct InnerType InnerType;
typedef struct EnumSymbolTableEntry EnumSymbolTableEntry;
typedef struct Variant Variant;
typedef struct VarSymbolTableEntry VarSymbolTableEntry;
typedef struct StructSymbolTableEntry StructSymbolTableEntry;

/***********************************************
 * Structs and functions for %union and yylval.
************************************************/

typedef enum PDT {
    U8,
    U16,
    U32,
    U64,
    I8,
    I16,
    I32,
    I64,
    PDT_FLOAT,
    PDT_CHAR,
    PDT_BOOL,
    PDT_STR,
} PDT;

typedef enum CType {
    CT_INT,
    CT_FLOAT,
    CT_CHAR,
    CT_BOOL,
    CT_STR,
    CT_VAR
} CType;



typedef struct Variant {
    std::string tag;
    std::string val;
    EnumSymbolTableEntry * este;
    Variant(std::string tag, std::string val, EnumSymbolTableEntry * este);
} Variant;

PDT get_pdt(char * s);

/***********************************************
 * Symbol table for the compiler.
************************************************/

typedef enum VarTypes {
    INT,
    FLOAT,
    BOOL,
    CHAR,
    STR,
    BUF,
    REF,
    STRUCT,
    ENUM,
    CART,
} VarTypes;

VarTypes get_vt(PDT pdt);

typedef enum Archetypes {
    GROUP,
    RING,
    FIELD,
    SPACE
} Archetypes;

struct Aux {
    Aux() {}
};

struct AuxSSTE : public Aux {
    StructSymbolTableEntry * sste;
    AuxSSTE(StructSymbolTableEntry * sste);
};

struct AuxESTE : public Aux {
    EnumSymbolTableEntry * este;
    AuxESTE(EnumSymbolTableEntry * este);
};

struct AuxCART : public Aux {
    std::deque<InnerType *> cart;
    AuxCART(std::deque<InnerType *> cart);
};


typedef struct InnerType {
    VarTypes core_type; // Yay types.
    int offset;
    int size;
    Aux * aux; // Pointer to symbol table entry for struct or enum. NULL for everything else.
    // IMPORTANT: ARRAY OF `InnerTypes` FOR CARTESIAN PRODUCT. 
    // CARTESIAN PRODUCT DOES NOT STACK.
    // LENGTH OF ARRAY CAN BE STORED IN SIZE.
    struct InnerType * next; // For big types. So, if you have &&&u32, is a stack of three REFs and a u32. 
    // If [u32], then a two level stack of buf, u32.
    // Unlike previously imagined, REF DOES NOT INVOLVE THE AUX POINTER. REF PUSHES ONTO THE STACK.
    InnerType(VarTypes core_type, int offset, int size);
} InnerType;

typedef struct Type {
    InnerType * head; // stack of types,  
    // int claimd[4]; // Claimed by group, ring, field, space. 
    int push_type(VarTypes core_type, int offset, int size, Aux * aux);
} Type;

// Type * make_type();
int typecmp(Type * t1, Type * t2);

/// @brief A single variable. No scope information is contained, coz multiple symbol tables. We can make a tree out of those.
typedef struct VarSymbolTableEntry {
    std::string name;
    // void * value; // Do we need this? Maybe useful for finite types: let q: Cyclic<10> = 20 as (Cyclic<10>); 
    Type * type;
    VarSymbolTableEntry(std::string name, Type * type);
} VarSymbolTableEntry;

// VarSymbolTableEntry * make_vste(char * name, void * value, Type * type);

/// @brief Contains all the variables in the current scope.
typedef struct VarSymbolTable {
    std::vector<VarSymbolTableEntry *> entries;
    int insert(VarSymbolTableEntry * vste);
    VarSymbolTableEntry * lookup(std::string name);
    // VarSymbolTable();
} VarSymbolTable;

// VarSymbolTable * make_vst();

typedef struct FunctionSymbolTableEntry FunctionSymbolTableEntry;
Type * get_param_type(FunctionSymbolTableEntry * f);

/// @brief Contains the symbol table for the current scope, and the current function. Tree structure. 
/// Each time a scope is entered, a new Scope is created, and the ScopeTree is updated.
/// Tree-like insertion not implemented, because you'll have the pointer to the current scope while parsing, so just use the add_child function.
typedef struct Scope {
    VarSymbolTable * vars; // Locals.
    FunctionSymbolTableEntry * current; // Maybe we need this, maybe we don't. Two way pointer still cleaner.
    struct Scope * parent; 
    struct Scope ** children; // Non-binary tree. Very queer.
    int nch; // Number of children.

} Scope;

typedef struct ScopeTree {
    Scope * root;
} ScopeTree;

Scope * make_scope();
ScopeTree * make_scope_tree();
void add_child(Scope * parent, Scope * child);

/// @brief A single function.
typedef struct FunctionSymbolTableEntry {
    std::string name;
    int numParams; // Redundant, but nvm.
    VarSymbolTable * params;
    ScopeTree * locals;
    Type * return_type;

    FunctionSymbolTableEntry(char * name, int numParams, VarSymbolTable * params);
} FunctionSymbolTableEntry;

// FunctionSymbolTableEntry * make_fste(char * name, int numParams, VarSymbolTable * params);

/// @brief Contains all the functions. There's only one of these. 
typedef struct FunctionSymbolTable {
    std::vector<FunctionSymbolTableEntry *> entries;
    int insert(FunctionSymbolTableEntry * fste);
    FunctionSymbolTableEntry * lookup(std::string name);
} FunctionSymbolTable;

// FunctionSymbolTable * make_func_st();


typedef struct Var {
    std::string name;
    Type * type;
    int offset;
    int size;
    Var(std::string name, Type * type, int offset, int size);
    Var() {
        this->name = "";
        this->type = NULL;
        this->offset = 0;
        this->size = 0;
    }
} Var;

/// @brief Not used for instances of a struct. This is used for the definition.
/// When a variable of this type is declared, once the entry is retrieved the aux field is used to store the name of the struct.
typedef struct StructSymbolTableEntry {
    std::string name;
    std::deque<Var> fields; 
    StructSymbolTableEntry(std::string name, std::deque<Var> fields);
    Type * make_struct_type();
} StructSymbolTableEntry;

// StructSymbolTableEntry * make_struct_ste(char * name, Var ** fields, int numFields);
// Type * make_struct_type(StructSymbolTableEntry * sste);


typedef struct StructSymbolTable {
    std::vector<StructSymbolTableEntry *> entries;
    int insert(StructSymbolTableEntry * sste);
    StructSymbolTableEntry * lookup(std::string name);   
} StructSymbolTable;

// StructSymbolTable * make_struct_st();
// int sst_insert(StructSymbolTable * sst, StructSymbolTableEntry * sste);
// StructSymbolTableEntry * sst_lookup(StructSymbolTable * sst, char * name);

typedef struct EnumSymbolTableEntry {
    std::string name;
    std::deque<std::string> fields;
    // int * values; // Corresponding ints.
    // int numFields;
    EnumSymbolTableEntry(std::string name, std::deque<std::string> fields);
} EnumSymbolTableEntry;

// EnumSymbolTableEntry * make_enum_ste(char * name, char ** fields, int numFields);

/// @brief Only one of these.
typedef struct EnumSymbolTable {
    // EnumSymbolTableEntry ** entries;
    // int size;
    // int capacity;
    std::vector<EnumSymbolTableEntry *> entries;
    int insert(EnumSymbolTableEntry * este);
    EnumSymbolTableEntry * lookup(std::string name);
} EnumSymbolTable;

// EnumSymbolTable * make_enum_st();
// int est_insert(EnumSymbolTable * est, EnumSymbolTableEntry * este);
// EnumSymbolTableEntry * est_lookup(EnumSymbolTable * est, char * name);

/// @brief We do not need an entry struct, because a forge is a function.
/// Only one of these.
typedef struct ForgeSymbolTable {
    FunctionSymbolTable * inner;
    int insert(FunctionSymbolTableEntry * fste);
    FunctionSymbolTableEntry * lookup(Type * t1, Type * t2);
} ForgeSymbolTable;

// ForgeSymbolTable * make_forge_st();
// int forge_insert(ForgeSymbolTable * fst, FunctionSymbolTableEntry * fste);
// FunctionSymbolTableEntry * forge_lookup(ForgeSymbolTable * fst, Type * t1, Type * t2);

typedef struct ClaimSymbolTableEntry {
    Type * type;
    Archetypes archetype;
    // We don't need more, ig?

    ClaimSymbolTableEntry(Type * type, Archetypes archetype);
} ClaimSymbolTableEntry;

// ClaimSymbolTableEntry * make_claim_ste(Type * type, Archetypes archetype);

typedef struct ClaimSymbolTable {
    std::vector<ClaimSymbolTableEntry *> entries;
    int insert(ClaimSymbolTableEntry * cste);
    ClaimSymbolTableEntry * lookup(Type * type, Archetypes archetype);
} ClaimSymbolTable;

// ClaimSymbolTable * make_claim_st();
// int cst_insert(ClaimSymbolTable * cst, ClaimSymbolTableEntry * cste);
// ClaimSymbolTableEntry * cst_lookup(ClaimSymbolTable * cst, Type * type, Archetypes archetype); 


/***********************************************
 * Globals
*/

StructSymbolTable struct_st;
EnumSymbolTable enum_st;
ForgeSymbolTable forge_st;
ClaimSymbolTable claim_st;
FunctionSymbolTable func_st;
VarSymbolTable var_st; // global variables only.

#endif
