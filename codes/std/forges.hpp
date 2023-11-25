#include <cstdint>
#include <tuple>
#include <stdexcept>
#include "structs.hpp"

// Forging std types:
//
// BigInt                       - from string, int
// Cyclic                       - from int
// Symmetric                    - from vector<int>, Alternating
// Alternating                  - from vector<int>, Symmetric
// Dihedral                     - from tuple<int, bool>
// Matrix                       - from vector<vector<T>>
// Polynomial                   - from vector<T>
// Rational                     - from tuple<int, int>, int
// Complex                      - from tuple<int, int>, tuple<Rational, Rational>, Rational, int
//
//
// Forging primitive types:
//
// int32_t                      - from BigInt, Cyclic, string
// double                       - from Rational, string
// tuple<int, int>              - from Rational
// tuple<Rational, Rational>    - from Complex
// tuple<int32_t, int32_t>      - from Complex
// string                       - from int, double, BigInt, Cyclic, Symmetric, Alternating, Dihedral, Rational, Complex
// vector<int>                  - from Symmetric, Alternating
// vector<vector<T>>            - from Matrix

BigInt forge_BigInt(const std::string str) {
    return BigInt(str);
}

BigInt forge_BigInt(int n) {
    return BigInt(n);
}

template<int N>
Cyclic<N> forge_Cyclic(int n) {
    return Cyclic<N>(n);
}

template<int N>
Symmetric<N> forge_Symmetric(std::vector<int> vec) {
    return Symmetric<N>(vec);
}

template<int N>
Symmetric<N> forge_Symmetric(const Alternating<N> alt) {
    return Symmetric<N>(alt.perm);
}

template<int N>
Alternating<N> forge_Alternating(const std::vector<int> vec) {
    return Alternating<N>(vec);
}

template<int N>
Alternating<N> forge_Alternating(const Symmetric<N> sym) {
    auto ret = Alternating<N>(sym.perm);
    ret.check_alt();
    return ret;
}

template<int N>
Dihedral<N> forge_Dihedral(const std::tuple<int, bool> tup) {
    return Dihedral<N>(std::get<0>(tup), std::get<1>(tup));
}

template<typename T>
Matrix<T> forge_Matrix(const std::vector<std::vector<T>> vec) {
    return Matrix<T>(vec);
}

template<typename T>
Polynomial<T> forge_Polynomial(const std::vector<T> vec) {
    return Polynomial<T>(vec);
}

Rational forge_Rational(const std::tuple<int, int> frac) {
    return Rational(std::get<0>(frac), std::get<1>(frac));
}

Rational forge_Rational(int n) {
    return Rational(n);
}

Complex forge_Complex(const std::tuple<int, int> frac) {
    return Complex(std::get<0>(frac), std::get<1>(frac));
}

Complex forge_Complex(const std::tuple<Rational, Rational> frac) {
    return Complex(std::get<0>(frac), std::get<1>(frac));
}

Complex forge_Complex(const Rational frac) {
    return Complex(frac);
}

Complex forge_Complex(int n) {
    return Complex(n);
}

int32_t forge_int32_t(const BigInt big) {
    return big.as_i32();
}

template<int N>
int32_t forge_int32_t(const Cyclic<N> cyc) {
    return cyc.r;
}

int32_t forge_int32_t(const std::string str) {
    return std::stoll(str);
}

double forge_double(const Rational rat) {
    auto r = mpq_class(rat.n, rat.d);
    return r.get_d();
}

double forge_double(const std::string str) {
    return std::stod(str);
}

std::tuple<int, int> forge_tuple_int_int(const Rational rat) {
    return std::make_tuple(rat.n.get_si(), rat.d.get_si());
}

std::tuple<Rational, Rational> forge_tuple_Rational_Rational(const Complex com) {
    return std::make_tuple(com.r, com.i);
}

std::tuple<int32_t, int32_t> forge_tuple_int32_t_int32_t(const Complex com) {
    return std::make_tuple(com.r.n.get_si(), com.i.n.get_si());
}

std::string forge_string(const int n) {
    return std::to_string(n);
}
std::string forge_string(const unsigned int n) {
    return std::to_string(n);
}

std::string forge_string(const double d) {
    return std::to_string(d);
}

std::string forge_string(const BigInt big) {
    return big.to_string();
}

template<int N>
std::string forge_string(const Cyclic<N> cyc) {
    return std::to_string(cyc.r);
}

template<int N>
std::string forge_string(const Symmetric<N> sym) {
    return sym.to_string();
}

template<int N>
std::string forge_string(const Alternating<N> alt) {
    return alt.to_string();
}

template<int N>
std::string forge_string(Dihedral<N> dih) {
    return dih.to_string();
}

std::string forge_string(Rational rat) {
    return rat.to_string();
}

std::string forge_string(Complex com) {
    return com.to_string();
}

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

// template<typename T>
std::string forge_string(const vector<int> vec) {
    std::string out = "";
    for(int i = 0; i < vec.size(); i++) {
        if(i) out += ", ";
        out += std::to_string(vec[i]);
    }
}


std::string forge_string(const vector<unsigned int> vec) {
    std::string out;
    for(int i = 0; i < vec.size(); i++) {
        if(i) out += ", ";
        out += std::to_string(vec[i]);
    }
}

// test: call all forges
/*int main() {
    auto big = forge_BigInt("1234567890123456789012345678901234567890");
    big = forge_BigInt(1234567890);
    auto cyc = forge_Cyclic<5>(3);
    auto sym = forge_Symmetric<5>({1, 2, 3, 4, 0});
    auto alt = forge_Alternating<5>({1, 2, 3, 4, 0});
    sym = forge_Symmetric<5>(alt);
    alt = forge_Alternating<5>(sym);
    auto dih = forge_Dihedral<5>(std::make_tuple(3, true));
    auto mat = forge_Matrix<int>({{1, 2, 3}, {4, 5, 6}});
    auto pol = forge_Polynomial<int>({1, 2, 3});
    auto rat = forge_Rational(std::make_tuple(1, 2));
    rat = forge_Rational(1);
    auto com = forge_Complex(std::make_tuple(1, 2));
    com = forge_Complex(std::make_tuple(rat, rat));
    com = forge_Complex(rat);
    com = forge_Complex(1);
    auto i32 = forge_int32_t(big);
    i32 = forge_int32_t(cyc);
    i32 = forge_int32_t("1234567890");
    auto dbl = forge_double(rat);
    dbl = forge_double("1.234567890");
    auto tup1 = forge_tuple_int_int(rat);
    auto tup2 = forge_tuple_Rational_Rational(com);
    auto tup3 = forge_tuple_int32_t_int32_t(com);
    auto str1 = forge_string(big);
    auto str2 = forge_string(cyc);
    auto str3 = forge_string(sym);
    auto str4 = forge_string(alt);
    auto str5 = forge_string(dih);
    auto str6 = forge_string(rat);
    auto str7 = forge_string(com);
    auto vec1 = forge_vector_int(sym);
    auto vec2 = forge_vector_int(alt);
    auto vec3 = forge_vector_vector_T(mat);

    return 0;
}*/
