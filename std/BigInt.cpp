#include <string>
#include <iostream>
#include <gmpxx.h>

struct BigInt {
    mpz_class n;
    BigInt(int n_) : n(n_) {}
    BigInt(mpz_class n_) : n(n_) {}
    BigInt(const std::string& s) : n(s) {}

    std::string to_string() const {
        return n.get_str();
    }

    BigInt zero() {
        return BigInt(0);
    }
    BigInt one() {
        return BigInt(1);
    }

    BigInt operator+(const BigInt& b) const {
        return BigInt(n + b.n);
    }
    BigInt operator-() const {
        return BigInt(-n);
    }

    BigInt operator*(const BigInt& b) const {
        return BigInt(n * b.n);
    }
};

int main() {
    auto a = BigInt(1);
    auto b = BigInt(2);
    auto c = a + b;
    auto d = BigInt("1234567890123456789012345678901234567890");
    std::cout << c.to_string() << '\n';
    std::cout << d.to_string() << '\n';
    return 0;
}
