#include <stdexcept>

// template function is_prime
template <int N>
constexpr bool is_prime() {
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

template <int N>
struct Cyclic {
    int r;
    Cyclic(int r_) : r(r_ >= 0 ? r_ % N : (r_ % N + N) % N) {}
    static Cyclic zero() {
        return Cyclic(0);
    }
    static Cyclic one() {
        return Cyclic(1);
    }

    // inv() only exists if N is prime
    Cyclic<N> inv() const {
        if constexpr (!is_prime<N>()) {
            throw std::runtime_error("inv() only exists if N is prime");
        }
        // modinv(r, N) using extended euclidean algorithm
        int a = r, b = N, x = 1, y = 0;
        while (a != 1) {
            int q = b / a;
            int t = b % a;
            b = a;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        return Cyclic(x);
    }

    Cyclic<N> operator+(const Cyclic<N> c) const {
        return Cyclic<N>((r + c.r) % N);
    }
    Cyclic<N> operator-() const {
        return Cyclic<N>(-r);
    }

    Cyclic<N> operator*(const Cyclic<N> c) const {
        return Cyclic<N>((r * c.r) % N);
    }

    bool operator==(const Cyclic<N> c) const {
        return r == c.r;
    }
    bool operator!=(const Cyclic<N> c) const {
        return r != c.r;
    }
};

static void check() {
    auto zero = Cyclic<5>::zero();
    auto one = Cyclic<5>::one();
    auto a = zero + zero;
    auto b = -zero;
    auto c = one.inv();
    auto d = one * one;

    {
        auto zero = Cyclic<6>::zero();
        // auto inv = zero.inv();
    }
}
