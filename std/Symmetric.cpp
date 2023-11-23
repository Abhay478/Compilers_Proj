// TODO: vector to Symmetric
template <int N>
struct Symmetric {
    int perm[N];
    static Symmetric zero() {
        Symmetric<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[i] = i;
        }
        return ret;
    }

    Symmetric<N> operator+(const Symmetric<N>& s) const {
        Symmetric<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[i] = perm[s.perm[i]];
        }
        return ret;
    }

    Symmetric<N> operator-() const {
        Symmetric<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[perm[i]] = i;
        }
        return ret;
    }

    bool operator==(const Symmetric<N>& s) const {
        for (int i = 0; i < N; i++) {
            if (perm[i] != s.perm[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Symmetric<N>& s) const {
        return !(*this == s);
    }
};

static void check() {
    auto zero = Symmetric<5>::zero();
    auto a = zero + zero;
    auto b = -zero;
}
