template <int N>
struct Alternating {
    int perm[N];

    Alternating(std::vector<int> vec) {
        if (vec.size() != N) {
            throw std::runtime_error("Cannot construct Alternating: inconsistent size");
        }
        std::vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (vec[i] < 0 || vec[i] >= N || visited[vec[i]]) {
                throw std::runtime_error("Cannot construct Alternating: invalid permutation");
            }
            visited[vec[i]] = true;
        }
        for (int i = 0; i < N; i++) {
            perm[i] = vec[i];
        }

        // check if permutation is alternating
        bool alternating = true;
        std::vector<bool> visited2(N, false);
        for (int i = 0; i < N; i++) {
            if (visited2[i]) {
                continue;
            }
            int j = i;
            int cycle_length = 0;
            while (!visited2[j]) {
                visited2[j] = true;
                j = perm[j];
                cycle_length++;
            }
            if (cycle_length % 2 == 0) {
                alternating = !alternating;
            }
        }
        if (!alternating) {
            throw std::runtime_error("Cannot construct Alternating: not alternating");
        }
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

    static Alternating zero() {
        Alternating<N> ret;
        for (int i = 0; i < N; i++) {
            ret.perm[i] = i;
        }
        return ret;
    }

    Alternating<N> operator+(const Alternating<N> s) const {
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

    bool operator==(const Alternating<N> s) const {
        for (int i = 0; i < N; i++) {
            if (perm[i] != s.perm[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Alternating<N> s) const {
        return !(*this == s);
    }
};
/*
static void check() {
    auto zero = Alternating<5>::zero();
    auto a = zero + zero;
    auto b = -zero;
}*/
