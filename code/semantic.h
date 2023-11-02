#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @brief No clue how to implement multiple refernces. 
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
} VarTypes;

typedef enum Archetypes {
    GROUP,
    RING,
    FIELD,
    SPACE
} Archetypes;

typedef struct AllType {
    VarTypes core_type; // Yay types.
    int offset;
    int size;
    void * aux; // Pointer to symbol table entry for struct or enum. Integer value for ref of buf. NULL for everything else.
} AllType;


/// @brief A single variable. No scope information is contained, coz multiple symbol tables. We can make a tre out of those.
typedef struct VarSymbolTableEntry {
    char *name;
    void *value; // Do we need this? Maybe useful for finite types: let q: Cyclic<10> = 20 as (Cyclic<10>); 
    AllType type;
    
} VarSymbolTableEntry;

VarSymbolTableEntry make_vste(char * name, void * value, AllType type, int offset, int size, void * aux);

/// @brief Contains all the variables in the current scope.
typedef struct VarSymbolTable {
    VarSymbolTableEntry *entries;
    int size;
    int capacity;
} VarSymbolTable;

int vst_insert(VarSymbolTable * st, VarSymbolTableEntry vste);
VarSymbolTableEntry * vst_lookup(VarSymbolTable * st, char * name);
VarSymbolTable make_vst();


/// @brief Contains the symbol table for the current scope, and the current function. Tree structure. 
/// Each time a scope is entered, a new Scope is created, and the ScopeTree is updated.
typedef struct Scope {
    VarSymbolTable * vars; // Locals.
    FunctionSymbolTableEntry * current; // Maybe we need this, maybe we don't. Two way pointer still cleaner.
    struct Scope * parent; 
    struct Scope ** children; // Non-binary tree. Very queer.
} Scope;

typedef struct ScopeTree {
    Scope * root;
} ScopeTree;

Scope make_scope();
ScopeTree make_scope_tree();

/// @brief A single function.
typedef struct FunctionSymbolTableEntry {
    char * name;
    int numParams;
    VarSymbolTable * params;
    // VarSymbolTable * locals; // Why do we need this? We don't.
    ScopeTree * locals;
    AllType return_type;
} FunctionSymbolTableEntry;

FunctionSymbolTableEntry make_fste(char * name, int numParams, VarSymbolTable * params);

/// @brief Contains all the functions. There's only one of these. 
typedef struct FunctionSymbolTable {
    FunctionSymbolTableEntry * entries;
    int size;
    int capacity;
} FunctionSymbolTable;

FunctionSymbolTable make_func_st();

int fst_insert(FunctionSymbolTable * fst, FunctionSymbolTableEntry fste);
FunctionSymbolTableEntry * fst_lookup(FunctionSymbolTable * fst, char * name);

typedef struct StructField {
    char * name;
    VarTypes type;
    int offset;
    int size;
} StructField;

/// @brief Not used for instances of a struct. This is used for the definition.
/// When a variable of this type is declared, once the entry is retrieved the aux field is used to store the name of the struct.
typedef struct StructSymbolTableEntry {
    char * name;
    StructField * fields; //
} StructSymbolTableEntry;


typedef struct StructSymbolTable {
    StructSymbolTableEntry * entries;
    int size;
    int capacity;
} StructSymbolTable;

StructSymbolTable make_struct_st();
int sst_insert(StructSymbolTable * sst, StructSymbolTableEntry sste);
StructSymbolTableEntry * sst_lookup(StructSymbolTable * sst, char * name);

typedef struct EnumSymbolTableEntry {
    char * name;
    char ** fields;
    int numFields;
} EnumSymbolTableEntry;

EnumSymbolTableEntry make_enum_ste(char * name, char ** fields, int numFields);

/// @brief Only one of these.
typedef struct EnumSymbolTable {
    EnumSymbolTableEntry * entries;
    int size;
    int capacity;
} EnumSymbolTable;

EnumSymbolTable make_enum_st();
int est_insert(EnumSymbolTable * est, EnumSymbolTableEntry este);
EnumSymbolTableEntry * est_lookup(EnumSymbolTable * est, char * name);

/// @brief We do not need an entry struct, because a forge is a function.
/// Only one of these.
typedef struct ForgeSymbolTable {
    FunctionSymbolTable inner;
} ForgeSymbolTable;

ForgeSymbolTable make_forge_st();
int forge_insert(ForgeSymbolTable * fst, FunctionSymbolTableEntry fste);
FunctionSymbolTableEntry * forge_lookup(ForgeSymbolTable * fst, char * name);

typedef struct ClaimSymbolTableEntry {
    char * name;
    AllType type;
    Archetypes archetype;
    // We don't need more, ig?
} ClaimSymbolTableEntry;

ClaimSymbolTableEntry make_claim_ste(char * name, AllType type, Archetypes archetype);

typedef struct ClaimSymbolTable {
    ClaimSymbolTableEntry * entries;
    int size;
    int capacity;
} ClaimSymbolTable;

ClaimSymbolTable make_claim_st();
int cst_insert(ClaimSymbolTable * cst, ClaimSymbolTableEntry cste);
ClaimSymbolTableEntry * cst_lookup(ClaimSymbolTable * cst, AllType type, Archetypes archetype); 
