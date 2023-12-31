/// initialize all symbol tables
/// func_st:
///     print(str) -> void
///     panic(str) -> void
/// claim_st:
///   groups:
///     Dihedral<n: int>
///     Symmetric<n: int>
///     Alternating<n: int>
///   rings:
///     Cyclic<n: int>              -> field if n is prime
///     BigInt
///     Matrix<F: Field>
///     Polynomial<F: Field>
///   fields:
///     Rational
///     Complex

#include "semantic.hpp"

using namespace std;

static Type *make_type(PDT pdt) {
    Type *t = new Type();
    t->push_type(get_vt(pdt), 0, 0, NULL);
    t->head->pdt = pdt;
    return t;
}

static Type *make_placeholder() {
    Type *t = new Type();
    t->push_type(PLACEHOLDER, 0, 0, NULL);
    return t;
}

static VarSymbolTable *make_params(vector<Var *> params) {
    auto vst = new VarSymbolTable();
    vst->entries = params;
    return vst;
}

/// only used within this file, so making some assumptions
static Type *get_type(const char *name) {
    auto g = gen_st.lookup(name);
    if (g != NULL) {
        auto types = new vector<GenericInner *>();
        for (auto t : g->types) {
            if (t.is_int) {
                types->push_back(new GenericInner(-1));
            } else {
                types->push_back(new GenericInner(make_placeholder()));
            }
        }
        Type *t = new Type();
        t->push_type(GEN, 0, 0, new Aux(g, types));
        return t;
    }

    auto s = struct_st.lookup(name);
    if (s != NULL) {
        return s->make_struct_type();
    }

    return NULL;
}

static Type *make_cart(vector<Type *> types) {
    Type *t = new Type();
    t->push_type(CART, 0, types.size(), new Aux(new vector<Type *>(types)));
    return t;
}

///     print(str)              -> void
///     panic(str)              -> void
///     push([T], T)            -> void
///     pop([T])                -> T
///     slice([T], int, int)    -> [T]
///     dot([T], [T])           -> T
static void init_func_st() {
    auto str_t = make_type(PDT_STR);
    auto str_arg = new Var("str", str_t);
    auto void_type = make_type(PDT_VOID);

    auto str_param = make_params({str_arg});

    auto print = new Function("print", str_param, void_type);
    func_st.insert(print);

    auto print_c = new Function("print_c", make_params({new Var("c", make_type(PDT_CHAR))}), void_type);
    func_st.insert(print_c);

    auto panic = new Function("panic", str_param, void_type);
    func_st.insert(panic);

    auto input = new Function("input", str_param, str_t);
    func_st.insert(input);

    auto buf = make_placeholder();
    buf->push_type(BUF, 0, 0, NULL);
    auto buf_arg = new Var("buf", buf);
    auto push_params = make_params({buf_arg, new Var("elem", make_placeholder())});
    auto push = new Function("push", push_params, void_type);
    func_st.insert(push);

    auto pop_params = make_params({buf_arg});
    auto pop = new Function("pop", pop_params, make_placeholder());
    func_st.insert(pop);

    auto slice_params = make_params({buf_arg, new Var("start", make_type(I32)), new Var("end", make_type(I32))});
    auto slice = new Function("slice", slice_params, buf);
    func_st.insert(slice);

    auto dot_params = make_params({buf_arg, buf_arg});
    auto dot = new Function("dot", dot_params, make_placeholder());
    func_st.insert(dot);
}

///     Dihedral<n: int>
///     Symmetric<n: int>
///     Alternating<n: int>
///     Cyclic<n: int>
///     Matrix<F: Ring>
///     Polynomial<F: Field>
static void init_gen_st() {
    vector<string> single_int_types = {"Dihedral", "Symmetric", "Alternating", "Cyclic"};
    for (auto i : single_int_types) {
        auto gste = new Generic(i, {GenericArg()});
        gen_st.insert(gste);
    }

    vector<string> single_ring_types = {"Matrix"};
    for (auto i : single_ring_types) {
        // auto gste = new Generic(i, {GenericArg(), GenericArg(RING)});
        auto gste = new Generic(i, {GenericArg(RING)});
        gen_st.insert(gste);
    }

    vector<string> single_field_types = {"Polynomial"};
    for (auto i : single_field_types) {
        auto gste = new Generic(i, {GenericArg(FIELD)});
        gen_st.insert(gste);
    }

    vector<string> space_types = {"Vec"};
    for (auto i : space_types) {
        auto gste = new Generic(i, {GenericArg(RING)});
        gen_st.insert(gste);
    }
}

///     BigInt
///     Rational
///     Complex
static void init_struct_st() {
    vector<string> types = {"BigInt", "Rational", "Complex"};
    for (auto i : types) {
        auto sste = new Struct(i, {});
        sste->builtin = true;
        struct_st.insert(sste);
    }
}

///   groups:
///     Dihedral<n: int>
///     Symmetric<n: int>
///     Alternating<n: int>
///   rings:
///     Cyclic<n: int>
///     BigInt
///     Matrix<F: Field>
///     Polynomial<F: Field>
///   fields:
///     Rational
///     Complex
static void init_claim_st() {
    vector<const char *> groups = {"Dihedral", "Symmetric", "Alternating"};
    vector<const char *> rings = {"Cyclic", "BigInt", "Matrix", "Polynomial"};
    vector<const char *> fields = {"Rational", "Complex"};
    vector<const char *> spaces = {"Vec"};

    // accumulate all types
    rings.insert(rings.end(), fields.begin(), fields.end());
    groups.insert(groups.end(), rings.begin(), rings.end());
    groups.insert(groups.end(), spaces.begin(), spaces.end());

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
    for (auto i : spaces) {
        auto type = get_type(i);
        claim_st.insert(new Claim(type, SPACE));
    }
}

static void init_forge_st() {
    /*

template<int N>
std::vector<int> forge_vector_int(const Symmetric<N> sym) {
    return sym.perm;
}

template<int N>
std::vector<int> forge_vector_int(const Alternating<N> alt) {
    return alt.perm;
}

template<typename T>
std::vector<std::vector<T>> forge_vector_vector_T(const Matrix<T> mat) {
    return mat.a;
}

    */

    auto buf = make_placeholder();
    buf->push_type(BUF, 0, 0, NULL);
    auto buf_arg = new Var("buf", buf);

    auto buf_buf = make_placeholder();
    buf_buf->push_type(BUF, 0, 0, NULL);
    buf_buf->push_type(BUF, 0, 0, NULL);
    auto buf_buf_arg = new Var("buf", buf_buf);

    auto buf_int = make_type(I32);
    buf_int->push_type(BUF, 0, 0, NULL);
    auto buf_int_arg = new Var("buf", buf_int);



    // forge string as BigInt
    auto forge_str_big_int_params = make_params({new Var("s", make_type(PDT_STR))});
    auto forge_str_big_int = new Function("forge_BigInt", forge_str_big_int_params, get_type("BigInt"));
    forge_st.insert(forge_str_big_int);

    // forge int as BigInt
    auto forge_int_big_int_params = make_params({new Var("n", make_type(I32))});
    auto forge_int_big_int = new Function("forge_BigInt", forge_int_big_int_params, get_type("BigInt"));
    forge_st.insert(forge_int_big_int);

    // forge int as Cyclic
    auto forge_int_cyclic_params = make_params({new Var("n", make_type(I32))});
    auto forge_int_cyclic = new Function("forge_Cyclic", forge_int_cyclic_params, get_type("Cyclic"));
    forge_st.insert(forge_int_cyclic);

    // forge vector<int> as Symmetric
    auto forge_vec_int_symmetric_params = make_params({ buf_int_arg });
    auto forge_vec_int_symmetric = new Function("forge_Symmetric", forge_vec_int_symmetric_params, get_type("Symmetric"));
    forge_st.insert(forge_vec_int_symmetric);

    // forge Alternating as Symmetric
    auto forge_alternating_symmetric_params = make_params({new Var("a", get_type("Alternating"))});
    auto forge_alternating_symmetric = new Function("forge_Symmetric", forge_alternating_symmetric_params, get_type("Symmetric"));
    forge_st.insert(forge_alternating_symmetric);

    // forge vector<int> as Alternating
    auto forge_vec_int_alternating_params = make_params({ buf_int_arg });
    auto forge_vec_int_alternating = new Function("forge_Alternating", forge_vec_int_alternating_params, get_type("Alternating"));
    forge_st.insert(forge_vec_int_alternating);

    // forge tuple<int, bool> as Dihedral
    auto forge_int_bool_dihedral_params = make_params({new Var("t", make_cart({make_type(I32), make_type(PDT_BOOL)}))});
    auto forge_int_bool_dihedral = new Function("forge_Dihedral", forge_int_bool_dihedral_params, get_type("Dihedral"));
    forge_st.insert(forge_int_bool_dihedral);

    // forge vector<vector<T>> as Matrix
    auto forge_vec_vec_t_matrix_params = make_params({ buf_buf_arg });
    auto forge_vec_vec_t_matrix = new Function("forge_Matrix", forge_vec_vec_t_matrix_params, get_type("Matrix"));
    forge_st.insert(forge_vec_vec_t_matrix);

    // forge vector<T> as Polynomial
    auto forge_vec_t_polynomial_params = make_params({ buf_arg });
    auto forge_vec_t_polynomial = new Function("forge_Polynomial", forge_vec_t_polynomial_params, get_type("Polynomial"));
    forge_st.insert(forge_vec_t_polynomial);

    // forge tuple<int, int> as Rational
    auto forge_int_int_rational_params = make_params({new Var("t", make_cart({make_type(I32), make_type(I32)}))});
    auto forge_int_int_rational = new Function("forge_Rational", forge_int_int_rational_params, get_type("Rational"));
    forge_st.insert(forge_int_int_rational);

    // forge tuple<BigInt, BigInt> as Rational
    auto forge_big_int_big_int_rational_params = make_params({new Var("t", make_cart({get_type("BigInt"), get_type("BigInt")}))});
    auto forge_big_int_big_int_rational = new Function("forge_Rational", forge_big_int_big_int_rational_params, get_type("Rational"));
    forge_st.insert(forge_big_int_big_int_rational);
    auto entry = forge_st.inner.entries[forge_st.inner.entries.size() - 1];

    // forge int as Rational
    auto forge_int_rational_params = make_params({new Var("n", make_type(I32))});
    auto forge_int_rational = new Function("forge_Rational", forge_int_rational_params, get_type("Rational"));
    forge_st.insert(forge_int_rational);

    // forge tuple<int, int> as Complex
    auto forge_int_int_complex_params = make_params({new Var("t", make_cart({make_type(I32), make_type(I32)}))});
    auto forge_int_int_complex = new Function("forge_Complex", forge_int_int_complex_params, get_type("Complex"));
    forge_st.insert(forge_int_int_complex);

    // forge tuple<Rational, Rational> as Complex
    auto forge_rational_rational_complex_params = make_params({new Var("t", make_cart({get_type("Rational"), get_type("Rational")}))});
    auto forge_rational_rational_complex = new Function("forge_Complex", forge_rational_rational_complex_params, get_type("Complex"));
    forge_st.insert(forge_rational_rational_complex);

    // forge Rational as Complex
    auto forge_rational_complex_params = make_params({new Var("r", get_type("Rational"))});
    auto forge_rational_complex = new Function("forge_Complex", forge_rational_complex_params, get_type("Complex"));
    forge_st.insert(forge_rational_complex);

    // forge int as Complex
    auto forge_int_complex_params = make_params({new Var("n", make_type(I32))});
    auto forge_int_complex = new Function("forge_Complex", forge_int_complex_params, get_type("Complex"));
    forge_st.insert(forge_int_complex);

    // forge BigInt as int
    auto forge_big_int_int_params = make_params({new Var("b", get_type("BigInt"))});
    auto forge_big_int_int = new Function("forge_int32_t", forge_big_int_int_params, make_type(I32));
    forge_st.insert(forge_big_int_int);

    // forge Cyclic as int
    auto forge_cyclic_int_params = make_params({new Var("c", get_type("Cyclic"))});
    auto forge_cyclic_int = new Function("forge_int32_t", forge_cyclic_int_params, make_type(I32));
    forge_st.insert(forge_cyclic_int);

    // forge string as int
    auto forge_str_int_params = make_params({new Var("s", make_type(PDT_STR))});
    auto forge_str_int = new Function("forge_int32_t", forge_str_int_params, make_type(I32));
    forge_st.insert(forge_str_int);

    // forge Rational as double
    auto forge_rational_double_params = make_params({new Var("r", get_type("Rational"))});
    auto forge_rational_double = new Function("forge_double", forge_rational_double_params, make_type(PDT_FLOAT));
    forge_st.insert(forge_rational_double);

    // forge string as double
    auto forge_str_double_params = make_params({new Var("s", make_type(PDT_STR))});
    auto forge_str_double = new Function("forge_double", forge_str_double_params, make_type(PDT_FLOAT));
    forge_st.insert(forge_str_double);

    // forge Rational as tuple<int, int>
    auto forge_rational_int_int_params = make_params({new Var("r", get_type("Rational"))});
    auto forge_rational_int_int = new Function("forge_tuple_int_int", forge_rational_int_int_params, make_cart({make_type(I32), make_type(I32)}));
    forge_st.insert(forge_rational_int_int);

    // forge Complex as tuple<Rational, Rational>
    auto forge_complex_rational_rational_params = make_params({new Var("c", get_type("Complex"))});
    auto forge_complex_rational_rational = new Function("forge_tuple_Rational_Rational", forge_complex_rational_rational_params, make_cart({get_type("Rational"), get_type("Rational")}));
    forge_st.insert(forge_complex_rational_rational);

    // forge Complex as tuple<int, int>
    auto forge_complex_int_int_params = make_params({new Var("c", get_type("Complex"))});
    auto forge_complex_int_int = new Function("forge_tuple_int_int", forge_complex_int_int_params, make_cart({make_type(I32), make_type(I32)}));
    forge_st.insert(forge_complex_int_int);

    // forge int as str
    auto forge_int_str_params = make_params({new Var("n", make_type(I32))});
    auto forge_int_str = new Function("forge_string", forge_int_str_params, make_type(PDT_STR));
    forge_st.insert(forge_int_str);

    // forge double as str
    auto forge_float_str_params = make_params({new Var("d", make_type(PDT_FLOAT))});
    auto forge_float_str = new Function("forge_string", forge_float_str_params, make_type(PDT_STR));
    forge_st.insert(forge_float_str);

    // forge BigInt as string
    auto forge_big_int_str_params = make_params({new Var("b", get_type("BigInt"))});
    auto forge_big_int_str = new Function("forge_string", forge_big_int_str_params, make_type(PDT_STR));
    forge_st.insert(forge_big_int_str);

    // forge Cyclic as string
    auto forge_cyclic_str_params = make_params({new Var("c", get_type("Cyclic"))});
    auto forge_cyclic_str = new Function("forge_string", forge_cyclic_str_params, make_type(PDT_STR));
    forge_st.insert(forge_cyclic_str);

    // forge Symmetric as string
    auto forge_symmetric_str_params = make_params({new Var("s", get_type("Symmetric"))});
    auto forge_symmetric_str = new Function("forge_string", forge_symmetric_str_params, make_type(PDT_STR));
    forge_st.insert(forge_symmetric_str);

    // forge Alternating as string
    auto forge_alternating_str_params = make_params({new Var("a", get_type("Alternating"))});
    auto forge_alternating_str = new Function("forge_string", forge_alternating_str_params, make_type(PDT_STR));
    forge_st.insert(forge_alternating_str);

    // forge Dihedral as string
    auto forge_dihedral_str_params = make_params({new Var("d", get_type("Dihedral"))});
    auto forge_dihedral_str = new Function("forge_string", forge_dihedral_str_params, make_type(PDT_STR));
    forge_st.insert(forge_dihedral_str);

    // forge Rational as string
    auto forge_rational_str_params = make_params({new Var("r", get_type("Rational"))});
    auto forge_rational_str = new Function("forge_string", forge_rational_str_params, make_type(PDT_STR));
    forge_st.insert(forge_rational_str);

    // forge Complex as string
    auto forge_complex_str_params = make_params({new Var("c", get_type("Complex"))});
    auto forge_complex_str = new Function("forge_string", forge_complex_str_params, make_type(PDT_STR));
    forge_st.insert(forge_complex_str);

    // forge Symmetric as vector<int>
    auto forge_symmetric_vec_int_params = make_params({new Var("s", get_type("Symmetric"))});
    auto forge_symmetric_vec_int = new Function("forge_vector_int", forge_symmetric_vec_int_params, buf_int);
    forge_st.insert(forge_symmetric_vec_int);

    // forge Alternating as vector<int>
    auto forge_alternating_vec_int_params = make_params({new Var("a", get_type("Alternating"))});
    auto forge_alternating_vec_int = new Function("forge_vector_int", forge_alternating_vec_int_params, buf_int);
    forge_st.insert(forge_alternating_vec_int);

    // forge Matrix as vector<vector<T>>
    auto forge_matrix_vec_vec_t_params = make_params({new Var("m", get_type("Matrix"))});
    auto forge_matrix_vec_vec_t = new Function("forge_vector_vector_T", forge_matrix_vec_vec_t_params, buf_buf);
    forge_st.insert(forge_matrix_vec_vec_t);
    // printf("%s -> %s\n", get_param_type(forge_matrix_vec_vec_t)->repr_cpp().c_str(), forge_matrix_vec_vec_t->return_type->repr_cpp().c_str());

    // forge vector<int> as string
    auto forge_vector_int_str_params = make_params({buf_int_arg});
    auto forge_vector_int_str = new Function("forge_string", forge_vector_int_str_params, make_type(PDT_STR));
    forge_st.insert(forge_vector_int_str);

    auto vec_bigint = get_type("BigInt");
    vec_bigint->push_type(BUF, 0, 0, NULL);
    auto vec_bigint_arg = new Var("vec", vec_bigint);

    // forge vector<BigInt> as string
    auto forge_vector_bigint_str_params = make_params({vec_bigint_arg});
    auto forge_vector_bigint_str = new Function("forge_string", forge_vector_bigint_str_params, make_type(PDT_STR));
    forge_st.insert(forge_vector_bigint_str);

    // forge Vec<T> as buf
    auto forge_vec_t_buf_params = make_params({new Var("v", get_type("Vec"))});
    auto forge_vec_t_buf = new Function("forge_buf", forge_vec_t_buf_params, buf);
    forge_st.insert(forge_vec_t_buf);

    // forge Vec<T> as string
    auto forge_vec_t_str_params = make_params({new Var("v", get_type("Vec"))});
    auto forge_vec_t_str = new Function("forge_string", forge_vec_t_str_params, make_type(PDT_STR));
    forge_st.insert(forge_vec_t_str);

    // forge buf as Vec<T>
    auto forge_buf_vec_t_params = make_params({buf_arg});
    auto forge_buf_vec_t = new Function("forge_Vec", forge_buf_vec_t_params, get_type("Vec"));
    forge_st.insert(forge_buf_vec_t);

}
void init_symbol_tables() {
    init_func_st();
    init_gen_st();
    init_struct_st();
    init_claim_st();
    init_forge_st();
}
