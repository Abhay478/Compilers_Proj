template <int N>
struct Dihedral {
    int r;
    bool s;
    Dihedral() : r(0), s(false) {}
    Dihedral(int r_, bool s) : r(r_ >= 0 ? r_ % N : (r_ % N + N) % N), s(s) {}
    static Dihedral zero() {
        return Dihedral();
    }

    Dihedral<N> operator+(const Dihedral<N> d) const {
        return Dihedral<N>((r + d.r) % N, s ^ d.s);
    }
    Dihedral<N> operator-() const {
        return Dihedral<N>(r, !s);
    }

    bool operator==(const Dihedral<N> d) const {
        return r == d.r && s == d.s;
    }
    bool operator!=(const Dihedral<N> d) const {
        return r != d.r || s != d.s;
    }
};

static void check() {
    auto zero = Dihedral<5>::zero();
    auto a = zero + zero;
    auto b = -zero;
}
