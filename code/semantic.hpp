#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>

#ifndef _SEMANTIC_H
#define _SEMANTIC_H

//! TODO
//! - Initialise symbol table with builtin functions/types and generics - that would be 3 symbol tables.
//! - Predeclare forge output variable?


/***********************************************
 * Struct declarations.
************************************************/

struct InnerType;
struct Enum;
struct Variant;
struct Var;
struct Struct;
struct Function;
struct Generic;

struct GenericInner;
struct Type;

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
    PDT_VOID,
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
    Enum * este;
    Variant(std::string tag, std::string val, Enum * este);
};

PDT get_pdt(char * s);
std::string get_pdt_str(PDT pdt);

/***********************************************
 * Symbol table for the compiler.
************************************************/

enum VarTypes {
    VOID,
    INT,
    FLOAT,
    BOOL,
    CHAR,
    STR,
    BUF,
    REF,
    GEN, // Library types, i.e. builtins. Generics and stuff.
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

union Aux {
    // STUCT
    Struct *sste;
    // ENUM
    Enum * este;
    // CART
    std::vector<Type *> * cart;
    // GEN
    struct {
        Generic * gste;
        std::vector<GenericInner *> *types;
    };

    Aux(Struct * sste) {this->sste = sste;}
    Aux(Enum * este) {this->este = este;}
    Aux(std::vector<Type *> * cart) {this->cart = cart;}
    Aux(Generic * gste, std::vector<GenericInner *> *types) {this->gste = gste; this->types = types;}

    int foo();

};

struct GenericInner {
    bool is_int;
    union {
        int lit_int;
        Type *type;
    };
    GenericInner(int lit_int);
    GenericInner(Type *type);
};


struct InnerType {
    VarTypes core_type; // Yay types.
    int offset;
    /**
     * For cartesian product (i.e. tuple), stores the tuple length.
     * For generic types with an integer parameter, stores the parameter. (Mat, InvMat, Cyclic, etc.)
     * Is 1 for BUF.
    */
    int size; 
    /// @brief For structs, enums, generics, and cartesian products.
    union {
        PDT pdt;
        // STUCT
        Struct *sste;
        // ENUM
        Enum * este;
        // CART
        std::vector<Type *> * cart;
        // GEN
        struct {
            Generic * gste;
            std::vector<GenericInner *> *types;
        };
    };

    void set_aux(Struct * sste) {this->sste = sste;}
    void set_aux(Enum * este) {this->este = este;}
    void set_aux(std::vector<Type *> * cart) {this->cart = cart;}
    void set_aux(Generic * gste, std::vector<GenericInner *> *types) {this->gste = gste; this->types = types;}

    std::string repr_cpp();

    /// @brief For buf, ref, and generics.
    struct InnerType * next; 
    InnerType(VarTypes core_type, int offset, int size);
};

struct Type {
    InnerType * head; // stack of types,  
    int push_type(VarTypes core_type, int offset, int size, Aux * aux);
    Type * pop_type();
    VarTypes core();

    std::string repr_cpp();
};

struct Expr: public Type {
private:
    Expr();
public:
    bool is_lvalue;
    std::string repr;
    Expr(Type * t, bool is_lvalue);
};

int typecmp(InnerType * t1, InnerType * t2, bool ignore_gen);
int typecmp(InnerType * t1, InnerType * t2);
int typecmp(Type * t1, Type * t2, bool ignore_gen);
int typecmp(Type * t1, Type * t2);

/// @brief A single variable. No scope information is contained, coz multiple symbol tables. We can make a tree out of those.
struct Var {
    std::string name;
    Type * type;
    int varno;
    Var() {
        name = "";
        type = NULL;
    }
    Var(std::string name, Type * type);

    std::string repr_cpp();
};

/// @brief Contains all the variables in the current scope.
struct VarSymbolTable {
    std::vector<Var *> entries;
    int insert(Var * vste);
    Var * lookup(std::string name);

    VarSymbolTable(std::vector<Var *> fields) {
        this->entries = fields;
    }

    VarSymbolTable() {
        entries = std::vector<Var *>();
    }
};

Type * get_param_type(Function * f);

/// @brief Contains the symbol table for the current scope, and the current function. Tree structure. 
/// Each time a scope is entered, a new Scope is created, and the ScopeTree is updated.
/// Tree-like insertion not implemented, because you'll have the pointer to the current scope while parsing, so just use the add_child function.
struct Scope {
    VarSymbolTable * vars; // Variables in the current scope.
    Scope * parent; 
    // std::vector<Scope *> children; // Don't need this, cuz single pass. Will revisit if needed.
    Scope() {
        vars = new VarSymbolTable();
        parent = NULL;
    }

    Var * lookup(std::string name);
    int insert(Var * vste) {
        return vars->insert(vste);
    }
};

/// @brief A single function.
struct Function {
    std::string name;
    VarSymbolTable * params; // Too much work to remove.
    Type * return_type;

    Function(std::string name, VarSymbolTable * params, Type * return_type);
};

// Function * make_fste(char * name, int numParams, VarSymbolTable * params);

/// @brief Contains all the functions. There's only one of these. 
struct FunctionSymbolTable {
    std::vector<Function *> entries;
    int insert(Function * fste);
    Function * lookup(std::string name);
};

// FunctionSymbolTable * make_func_st();

/// @brief Not used for instances of a struct. This is used for the definition.
/// When a variable of this type is declared, once the entry is retrieved the aux field is used to store the name of the struct.
struct Struct {
    std::string name;
    std::vector<Var *> fields; 
    FunctionSymbolTable * methods;
    Struct(std::string name, std::vector<Var *> fields);
    Type * make_struct_type();
    Var* fieldLookup(std::string);
};


struct StructSymbolTable {
    std::vector<Struct *> entries;
    int insert(Struct * sste);
    Struct * lookup(std::string name);   
};

struct Enum {
    std::string name;
    std::vector<std::string> fields;
    Enum(std::string name, std::vector<std::string> fields);
};

/// @brief Only one of these.
struct EnumSymbolTable {
    // Enum ** entries;
    // int size;
    // int capacity;
    std::vector<Enum *> entries;
    int insert(Enum * este);
    Enum * lookup(std::string name);
};


/// @brief We do not need an entry struct, because a forge is a function.
/// Only one of these.
struct ForgeSymbolTable {
    FunctionSymbolTable inner;
    int insert(Function * fste);
    Function * lookup(Type * t1, Type * t2);
};

struct Claim {
    // `type` claims `archetype` with associated type `over`.
    Type * type;
    Archetypes archetype;
    Type * over;
    // We don't need more, ig?

    Claim(Type * type, Archetypes archetype);
};

struct ClaimSymbolTable {
    std::vector<Claim *> entries;
    int insert(Claim * cste);
    Claim * lookup(Type * type, Archetypes archetype);
};

struct GenericArg {
    bool is_int;
    Archetypes archetype;
    GenericArg(); // int
    GenericArg(Archetypes archetype); // archetype
};

struct Generic {
    std::string name;
    std::vector<GenericArg> types;
    Generic(std::string name, std::vector<GenericArg> types) {
        this->name = name;
        this->types = types;
    }
};

struct GenSymbolTable {
    std::vector<Generic *> entries;
    int insert(Generic * fste);
    Generic * lookup(std::string name);
};


/**********************************
 * Typecheck functions
*/

Expr * int_float_check(Expr * t1, Expr * t2);
Expr * mult_type_check_arithmetic(Expr *t1, Expr *t2);
Expr * div_type_check_arithmetic(Expr *t1, Expr *t2);
Expr * modulus_type_check_arithmetic(Expr *t1, Expr *t2);
Expr * add_sub_type_check_arithmetic(Expr *t1, Expr *t2);
Expr * and_or_type_check(Expr *t1, Expr *t2);
Expr * cmp_op_type_check_arithmetic(Expr *t1, Expr *t2);
Expr * eq_op_type_check_arithmetic(Expr *t1, Expr *t2);
Expr * in_type_check(Expr *t1, Expr *t2);
VarTypes convert_constType_to_varType(CType t);


/***********************************************
 * Globals
*/

extern StructSymbolTable struct_st;
extern EnumSymbolTable enum_st;
extern ForgeSymbolTable forge_st;
extern ClaimSymbolTable claim_st;
extern FunctionSymbolTable func_st;
extern GenSymbolTable gen_st;

extern Scope * current_scope;

void init_symbol_tables();

#define RED_ESCAPE "\x1B[1;31;40m"
#define BLUE_ESCAPE "\x1B[1;34;40m"
#define GREEN_ESCAPE "\x1B[1;32;40m"
#define RESET_ESCAPE "\x1B[0;37;40m"

#endif
