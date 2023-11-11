/// initialize all symbol tables
/// func_st:
///     print(str) -> void
///     panic(str) -> void
/// claim_st:
///   groups:
///     Dihedral<n: int>
///     Symmetric<n: int>
///     Alternating<n: int>
///     InvMat<n: int, F: Field>
///   rings:
///     Cyclic<n: int>              -> field if n is prime
///     BigInt
///     Matrix<n: int, F: Field>
///     Polynomial<F: Field>
///   fields:
///     BigRational
///     BigComplexRational

#include "semantic.hpp"

using namespace std;

static Type *make_type(PDT pdt) {
    Type *t = new Type();
    t->push_type(get_vt(pdt), 0, 0, NULL);
    return t;
}

static VarSymbolTable *make_params(vector<Var *> params) {
    auto vst = new VarSymbolTable();
    vst->entries = params;
    return vst;
}

///     print(str) -> void
///     panic(str) -> void
static void init_func_st() {
    auto print_params = make_params({new Var("str", make_type(PDT_STR))});
    auto print = new Function("print", print_params, make_type(PDT_VOID));
    func_st.insert(print);

    auto panic_params = make_params({new Var("msg", make_type(PDT_STR))});
    auto panic = new Function("print", panic_params, make_type(PDT_VOID));
    func_st.insert(panic);
}

///     Dihedral<n: int>
///     Symmetric<n: int>
///     Alternating<n: int>
///     Cyclic<n: int>
///     InvMat<n: int, F: Field>
///     Matrix<n: int, F: Field>
///     Polynomial<F: Field>
static void init_gen_st() {
    vector<string> single_int_types = {"Dihedral", "Symmetric", "Alternating", "Cyclic"};
    for (auto i : single_int_types) {
        auto gste = new Generic(i, {GenericArg()});
        gen_st.insert(gste);
    }

    vector<string> int_field_types = {"InvMat", "Matrix"};
    for (auto i : int_field_types) {
        auto gste = new Generic(i, {GenericArg(), GenericArg(FIELD)});
        gen_st.insert(gste);
    }

    vector<string> single_field_types = {"Polynomial"};
    for (auto i : single_field_types) {
        auto gste = new Generic(i, {GenericArg(FIELD)});
        gen_st.insert(gste);
    }
}

///     BigInt
///     BigRational
///     BigComplexRational
static void init_struct_st() {
    vector<string> types = {"BigInt", "BigRational", "BigComplexRational"};
    for (auto i : types) {
        auto sste = new Struct(i, {});
        struct_st.insert(sste);
    }
}

/// only used within this file, so making some assumptions
static Type *get_type(const char *name) {
    auto g = gen_st.lookup(name);
    if (g != NULL) {
        Type *t = new Type();
        t->push_type(GEN, 0, 0, new Aux(g, NULL));
        return t;
    }

    auto s = struct_st.lookup(name);
    if (s != NULL) {
        return s->make_struct_type();
    }

    return NULL;
}

///   groups:
///     Dihedral<n: int>
///     Symmetric<n: int>
///     Alternating<n: int>
///     InvMat<n: int, F: Field>
///   rings:
///     Cyclic<n: int>
///     BigInt
///     Matrix<n: int, F: Field>
///     Polynomial<F: Field>
///   fields:
///     BigRational
///     BigComplexRational
static void init_claim_st() {
    vector<const char *> groups = {"Dihedral", "Symmetric", "Alternating", "InvMat"};
    vector<const char *> rings = {"Cyclic", "BigInt", "Matrix", "Polynomial"};
    vector<const char *> fields = {"BigRational", "BigComplexRational"};

    // accumulate all types
    rings.insert(rings.end(), fields.begin(), fields.end());
    groups.insert(groups.end(), rings.begin(), rings.end());

    for (auto i : groups) {
        auto type = get_type(i);
        claim_st.insert(new Claim(type, GROUP));
    }
    for (auto i : rings) {
        auto type = get_type(i);
        claim_st.insert(new Claim(type, RING));
    }
    for (auto i : fields) {
        auto type = get_type(i);
        claim_st.insert(new Claim(type, FIELD));
    }
}

void init_symbol_tables() {
    init_func_st();
    init_gen_st();
    init_struct_st();
    init_claim_st();
}
