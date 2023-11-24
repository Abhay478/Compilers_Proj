struct Complex {
    Rational r, i;
    Complex(Rational r_) : r(r_), i(Rational::zero()) {}
    Complex(Rational r_, Rational i_) : r(r_), i(i_) {}

    std::string to_string() {
        return r.to_string() + " + " + i.to_string() + "i";
    }

    static Complex zero() {
        return Complex(Rational::zero());
    }
    static Complex one() {
        return Complex(Rational::one());
    }

    Complex operator+(Complex b) {
        return Complex(r + b.r, i + b.i);
    }
    Complex operator-() {
        return Complex(-r, -i);
    }

    static Complex inv(Complex c) {
        auto d = c.r * c.r + c.i * c.i;
        return Complex(c.r * d.inv(), -c.i * d.inv());
    }

    Complex operator*(Complex b) {
        return Complex(r * b.r + -(i * b.i), r * b.i + i * b.r);
    }
};

/*int main() {
    auto a = Complex(Rational(1, 2), Rational(1, 3));
    auto b = Complex(Rational(1, 3), Rational(1, 4));
    auto c = Complex(Rational(1, 6), Rational(1, 12));
    auto d = a + b;
    return 0;
}*/
