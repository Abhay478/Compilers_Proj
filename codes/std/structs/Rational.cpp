#include <string>
#include "gmpxx.h"

struct Rational {
    mpz_class n, d;
    Rational() : n(0), d(1) {}
    Rational(int n_) : n(n_), d(1) {}
    Rational(mpz_class n_) : n(n_), d(1) {}
    Rational(mpz_class n_, mpz_class d_) : n(n_), d(d_) {
        normalize();
    }

    void normalize() {
        if (d < 0) {
            n = -n;
            d = -d;
        }
        auto g = gcd(n, d);
        n /= g;
        d /= g;
    }

    std::string to_string() {
        normalize();
        return n.get_str() + "/" + d.get_str();
    }

    static Rational zero() {
        return Rational(0);
    }
    static Rational one() {
        return Rational(1);
    }
    Rational inv() {
        return Rational(d, n);
    }

    Rational operator+(Rational b) {
        return Rational(n * b.d + b.n * d, d * b.d);
    }
    Rational operator-() {
        return Rational(-n, d);
    }

    Rational operator*(Rational b) {
        return Rational(n * b.n, d * b.d);
    }
};

/*int main() {
    auto a = Rational(1, 2);
    auto b = Rational(1, 3);
    auto c = Rational(1, 6);
    auto d = a + b;
    return 0;
}*/
