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

struct InnerType;
struct EnumSymbolTableEntry;
struct Variant;
struct VarSymbolTableEntry;
struct StructSymbolTableEntry;
struct FunctionSymbolTableEntry;

/***********************************************
 * Structs and functions for %union and yylval.
************************************************/

enum PDT {
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
};

enum CType {
    CT_INT,
    CT_FLOAT,
    CT_CHAR,
    CT_BOOL,
    CT_STR,
    CT_VAR
};



struct Variant {
    std::string tag;
    std::string val;
    EnumSymbolTableEntry * este;
    Variant(std::string tag, std::string val, EnumSymbolTableEntry * este);
};

PDT get_pdt(char * s);

/***********************************************
 * Symbol table for the compiler.
************************************************/

enum VarTypes {
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
};

VarTypes get_vt(PDT pdt);

enum Archetypes {
    GROUP,
    RING,
    FIELD,
    SPACE
};

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


struct InnerType {
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
};

struct Type {
    InnerType * head; // stack of types,  
    // int claimd[4]; // Claimed by group, ring, field, space. 
    int push_type(VarTypes core_type, int offset, int size, Aux * aux);
};

// Type * make_type();
int typecmp(Type * t1, Type * t2);

/// @brief A single variable. No scope information is contained, coz multiple symbol tables. We can make a tree out of those.
struct VarSymbolTableEntry {
    std::string name;
    // void * value; // Do we need this? Maybe useful for finite types: let q: Cyclic<10> = 20 as (Cyclic<10>); 
    Type * type;
    VarSymbolTableEntry(std::string name, Type * type);
};

// VarSymbolTableEntry * make_vste(char * name, void * value, Type * type);

/// @brief Contains all the variables in the current scope.
struct VarSymbolTable {
    std::vector<VarSymbolTableEntry *> entries;
    int insert(VarSymbolTableEntry * vste);
    VarSymbolTableEntry * lookup(std::string name);
    // VarSymbolTable();
};

// VarSymbolTable * make_vst();

Type * get_param_type(FunctionSymbolTableEntry * f);

/// @brief Contains the symbol table for the current scope, and the current function. Tree structure. 
/// Each time a scope is entered, a new Scope is created, and the ScopeTree is updated.
/// Tree-like insertion not implemented, because you'll have the pointer to the current scope while parsing, so just use the add_child function.
struct Scope {
    VarSymbolTable * vars; // Locals.
    FunctionSymbolTableEntry * current; // Maybe we need this, maybe we don't. Two way pointer still cleaner.
    struct Scope * parent; 
    struct Scope ** children; // Non-binary tree. Very queer.
    int nch; // Number of children.

};

struct ScopeTree {
    Scope * root;
};

Scope * make_scope();
ScopeTree * make_scope_tree();
void add_child(Scope * parent, Scope * child);

/// @brief A single function.
struct FunctionSymbolTableEntry {
    std::string name;
    int numParams; // Redundant, but nvm.
    VarSymbolTable * params;
    ScopeTree * locals;
    Type * return_type;

    FunctionSymbolTableEntry(char * name, int numParams, VarSymbolTable * params);
};

// FunctionSymbolTableEntry * make_fste(char * name, int numParams, VarSymbolTable * params);

/// @brief Contains all the functions. There's only one of these. 
struct FunctionSymbolTable {
    std::vector<FunctionSymbolTableEntry *> entries;
    int insert(FunctionSymbolTableEntry * fste);
    FunctionSymbolTableEntry * lookup(std::string name);
};

// FunctionSymbolTable * make_func_st();


struct Var {
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
};

/// @brief Not used for instances of a struct. This is used for the definition.
/// When a variable of this type is declared, once the entry is retrieved the aux field is used to store the name of the struct.
struct StructSymbolTableEntry {
    std::string name;
    std::deque<Var> fields; 
    StructSymbolTableEntry(std::string name, std::deque<Var> fields);
    Type * make_struct_type();
};

// StructSymbolTableEntry * make_struct_ste(char * name, Var ** fields, int numFields);
// Type * make_struct_type(StructSymbolTableEntry * sste);


struct StructSymbolTable {
    std::vector<StructSymbolTableEntry *> entries;
    int insert(StructSymbolTableEntry * sste);
    StructSymbolTableEntry * lookup(std::string name);   
};

// StructSymbolTable * make_struct_st();
// int sst_insert(StructSymbolTable * sst, StructSymbolTableEntry * sste);
// StructSymbolTableEntry * sst_lookup(StructSymbolTable * sst, char * name);

struct EnumSymbolTableEntry {
    std::string name;
    std::deque<std::string> fields;
    // int * values; // Corresponding ints.
    // int numFields;
    EnumSymbolTableEntry(std::string name, std::deque<std::string> fields);
};

// EnumSymbolTableEntry * make_enum_ste(char * name, char ** fields, int numFields);

/// @brief Only one of these.
struct EnumSymbolTable {
    // EnumSymbolTableEntry ** entries;
    // int size;
    // int capacity;
    std::vector<EnumSymbolTableEntry *> entries;
    int insert(EnumSymbolTableEntry * este);
    EnumSymbolTableEntry * lookup(std::string name);
};

// EnumSymbolTable * make_enum_st();
// int est_insert(EnumSymbolTable * est, EnumSymbolTableEntry * este);
// EnumSymbolTableEntry * est_lookup(EnumSymbolTable * est, char * name);

/// @brief We do not need an entry struct, because a forge is a function.
/// Only one of these.
struct ForgeSymbolTable {
    FunctionSymbolTable * inner;
    int insert(FunctionSymbolTableEntry * fste);
    FunctionSymbolTableEntry * lookup(Type * t1, Type * t2);
};

// ForgeSymbolTable * make_forge_st();
// int forge_insert(ForgeSymbolTable * fst, FunctionSymbolTableEntry * fste);
// FunctionSymbolTableEntry * forge_lookup(ForgeSymbolTable * fst, Type * t1, Type * t2);

struct ClaimSymbolTableEntry {
    Type * type;
    Archetypes archetype;
    // We don't need more, ig?

    ClaimSymbolTableEntry(Type * type, Archetypes archetype);
};

// ClaimSymbolTableEntry * make_claim_ste(Type * type, Archetypes archetype);

struct ClaimSymbolTable {
    std::vector<ClaimSymbolTableEntry *> entries;
    int insert(ClaimSymbolTableEntry * cste);
    ClaimSymbolTableEntry * lookup(Type * type, Archetypes archetype);
};

// ClaimSymbolTable * make_claim_st();
// int cst_insert(ClaimSymbolTable * cst, ClaimSymbolTableEntry * cste);
// ClaimSymbolTableEntry * cst_lookup(ClaimSymbolTable * cst, Type * type, Archetypes archetype); 


/***********************************************
 * Globals
*/

extern StructSymbolTable struct_st;
extern EnumSymbolTable enum_st;
extern ForgeSymbolTable forge_st;
extern ClaimSymbolTable claim_st;
extern FunctionSymbolTable func_st;
extern VarSymbolTable var_st; // global variables only.

#endif