#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @brief No clue how to implement multiple refernces. That's a tomorrow problem.
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

/// @brief A single variable. No scope information is contained, coz multiple symbol tables. We can make a tre out of those.
typedef struct VarSymbolTableEntry {
    char *name;
    void *value; // Do we need this? Maybe useful for finite types: let q: Cyclic<10> = 20 as (Cyclic<10>); 
    VarTypes type; // Yay types.
    int offset;
    int size;
    void * aux; // Pointer to symbol table entry for struct or enum. Integer value for ref of buf. NULL for everything else.
} VarSymbolTableEntry;

VarSymbolTableEntry make_vste(char * name, void * value, VarTypes type, int offset, int size, void * aux);

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
} FunctionSymbolTableEntry;

FunctionSymbolTableEntry make_fste(char * name, int numParams, VarSymbolTable * params, ScopeTree * locals);

/// @brief Contains all the functions. There's only one of these. 
typedef struct FunctionSymbolTable {
    FunctionSymbolTableEntry * entries;
    int size;
    int capacity;
} FunctionSymbolTable;

FunctionSymbolTable make_fst();

int fst_insert(FunctionSymbolTable * fst, FunctionSymbolTableEntry fste);

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