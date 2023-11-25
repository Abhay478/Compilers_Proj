#include <vector>

template <typename T>
struct Polynomial {
    std::vector<T> coeffs;
    Polynomial()  {
        coeffs = {T::zero()};
    }
    Polynomial(const std::vector<T> coeffs_) : coeffs(coeffs_) {}

    static Polynomial zero() {
        auto z = _zero<T>();
        return Polynomial(std::vector<T>(0, z));
    }
    static Polynomial one() {
        return Polynomial(std::vector<T>(1, _one<T>()));
    }

    Polynomial operator+(const Polynomial p) const {
        std::vector<T> ret(std::max(coeffs.size(), p.coeffs.size()));
        for (int i = 0; i < coeffs.size(); i++) {
            ret[i] = ret[i] + coeffs[i];
        }
        for (int i = 0; i < p.coeffs.size(); i++) {
            ret[i] = ret[i] + p.coeffs[i];
        }
        return Polynomial(ret);
    }

    Polynomial operator-() const {
        std::vector<T> ret(coeffs.size());
        for (int i = 0; i < coeffs.size(); i++) {
            ret[i] = -coeffs[i];
        }
        return Polynomial(ret);
    }

    Polynomial operator*(const Polynomial p) const {
        std::vector<T> ret(coeffs.size() + p.coeffs.size() - 1);
        for (int i = 0; i < coeffs.size(); i++) {
            for (int j = 0; j < p.coeffs.size(); j++) {
                ret[i + j] = ret[i + j] + coeffs[i] * p.coeffs[j];
            }
        }
        return Polynomial(ret);
    }
};

/*static void check() {
    auto n = _zero<int>();
    Polynomial<int> p = Polynomial<int>::zero();
    Polynomial<int> q = Polynomial<int>::one();
    Polynomial<int> r = p + q;
    Polynomial<int> s = -r;
    Polynomial<int> t = r * s;

    auto x = Polynomial<BigInt>({BigInt::zero(), BigInt::one()});
}*/
