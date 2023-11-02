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

typedef struct InnerType {
    VarTypes core_type; // Yay types.
    int offset;
    int size;
    void * aux; // Pointer to symbol table entry for struct or enum. NULL for everything else.
    struct InnerType * next; // For big types. So, if you have &&&u32, is a stack of three REFs and a u32. 
    // If [u32], then a two level stack of buf, u32.
    // Unlike previously imagined, REF DOES NOT INVOLVE THE AUX POINTER. REF PUSHES ONTO THE STACK.
} InnerType;

typedef struct Type {
    InnerType * head; // stack of types, 
} Type;

Type make_type();
int typecmp(Type * t1, Type * t2);

/// @brief A single variable. No scope information is contained, coz multiple symbol tables. We can make a tre out of those.
typedef struct VarSymbolTableEntry {
    char *name;
    void *value; // Do we need this? Maybe useful for finite types: let q: Cyclic<10> = 20 as (Cyclic<10>); 
    Type type;
    
} VarSymbolTableEntry;

VarSymbolTableEntry make_vste(char * name, void * value, Type type, int offset, int size, void * aux);

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

Scope make_scope();
ScopeTree make_scope_tree();
void add_child(Scope * parent, Scope * child);

/// @brief A single function.
typedef struct FunctionSymbolTableEntry {
    char * name;
    int numParams;
    VarSymbolTable * params;
    // VarSymbolTable * locals; // Why do we need this? We don't.
    ScopeTree * locals;
    Type return_type;
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
    Type type;
    Archetypes archetype;
    // We don't need more, ig?
} ClaimSymbolTableEntry;

ClaimSymbolTableEntry make_claim_ste(char * name, Type type, Archetypes archetype);

typedef struct ClaimSymbolTable {
    ClaimSymbolTableEntry * entries;
    int size;
    int capacity;
} ClaimSymbolTable;

ClaimSymbolTable make_claim_st();
int cst_insert(ClaimSymbolTable * cst, ClaimSymbolTableEntry cste);
ClaimSymbolTableEntry * cst_lookup(ClaimSymbolTable * cst, Type type, Archetypes archetype); 
