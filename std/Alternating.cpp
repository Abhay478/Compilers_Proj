// TODO: vector to Alternating
template <int N>
class Alternating {
    int perm[N];
public:
    static Alternating zero() {
        Alternating<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[i] = i;
        }
        return ret;
    }

    Alternating<N> operator+(const Alternating<N>& s) const {
        Alternating<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[i] = perm[s.perm[i]];
        }
        return ret;
    }

    Alternating<N> operator-() const {
        Alternating<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[perm[i]] = i;
        }
        return ret;
    }

    bool operator==(const Alternating<N>& s) const {
        for (int i = 0; i < N; i++) {
            if (perm[i] != s.perm[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Alternating<N>& s) const {
        return !(*this == s);
    }
};

static void check() {
    auto zero = Alternating<5>::zero();
    auto a = zero + zero;
    auto b = -zero;
}
