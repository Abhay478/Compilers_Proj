template <int N>
struct Symmetric {
    std::vector<int> perm;

    Symmetric(std::vector<int> vec) {
        if (vec.size() != N) {
            f_panic("Cannot construct Symmetric: inconsistent size");
        }
        std::vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (vec[i] < 0 || vec[i] >= N || visited[vec[i]]) {
                f_panic("Cannot construct Alternating: invalid permutation");
            }
            visited[vec[i]] = true;
        }
        for (int i = 0; i < N; i++) {
            perm[i] = vec[i];
        }
    }

    static Symmetric zero() {
        Symmetric<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[i] = i;
        }
        return ret;
    }

    std::string to_string() const {
        // find cycles
        std::vector<int> cycle_starts;
        std::vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                continue;
            }
            cycle_starts.push_back(i);
            int j = perm[i];
            while (j != i) {
                visited[j] = true;
                j = perm[j];
            }
        }

        // print cycles
        std::string ret = "";
        for (int i = 0; i < cycle_starts.size(); i++) {
            int j = cycle_starts[i];
            if (j == perm[j]) {
                continue;
            }
            ret += "(" + std::to_string(j);
            j = perm[j];
            while (j != cycle_starts[i]) {
                ret += " " + std::to_string(j);
                j = perm[j];
            }
            ret += ")";
        }
        if (ret == "") {
            ret = "()";
        }
        return ret;
    }

    Symmetric<N> operator+(const Symmetric<N> s) const {
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

    bool operator==(const Symmetric<N> s) const {
        for (int i = 0; i < N; i++) {
            if (perm[i] != s.perm[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Symmetric<N> s) const {
        return !(*this == s);
    }
};
/*
static void check() {
    auto zero = Symmetric<5>::zero();
    auto a = zero + zero;
    auto b = -zero;
}*/
