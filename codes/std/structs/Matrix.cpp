#include <vector>
template <typename T>
struct Matrix {
    std::vector<std::vector<T>> a;
    Matrix() {}
    Matrix(int m, int n) : a(m, std::vector<T>(n)) {}
    Matrix(const std::vector<std::vector<T>> a_) {
        if (a_.empty()) {
            a = a_;
            return;
        }
        int n = a_[0].size();
        for (int i = 0; i < a_.size(); i++) {
            if (a_[i].size() != n) {
                f_panic("Cannot construct Matrix: inconsistent column size");
            }
        }
        a = a_;
    }

    static Matrix zero(int m, int n) {
        return Matrix(m, n);
    }

    static Matrix one(int n) {
        Matrix ret(n, n);
        for (int i = 0; i < n; i++) {
            ret.a[i][i] = 1;
        }
        return ret;
    }

    // TODO: read this
    Matrix inv() const {
        if (a.size() != a[0].size()) {
            f_panic("Cannot invert non-square Matrix");
        }
        int n = a.size();
        Matrix ret = one(n);
        Matrix b = *this;
        for (int i = 0; i < n; i++) {
            int p = i;
            for (int j = i + 1; j < n; j++) {
                if (b.a[j][i] > b.a[p][i]) {
                    p = j;
                }
            }
            if (b.a[p][i] == 0) {
                f_panic("Cannot invert Matrix: singular");
            }
            swap(b.a[i], b.a[p]);
            swap(ret.a[i], ret.a[p]);
            T d = b.a[i][i];
            for (int j = 0; j < n; j++) {
                b.a[i][j] /= d;
                ret.a[i][j] /= d;
            }
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                T d = b.a[j][i];
                for (int k = 0; k < n; k++) {
                    b.a[j][k] -= b.a[i][k] * d;
                    ret.a[j][k] -= ret.a[i][k] * d;
                }
            }
        }
        return ret;
    }

    Matrix operator+(const Matrix m) const {
        if (a.size() != m.a.size() || a[0].size() != m.a[0].size()) {
            f_panic("Cannot add/mul Matrix: inconsistent size");
        }
        Matrix ret(a.size(), a[0].size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                ret.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        return ret;
    }

    Matrix operator-() const {
        Matrix ret(a.size(), a[0].size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                ret.a[i][j] = -a[i][j];
            }
        }
        return ret;
    }

    Matrix operator*(const Matrix m) const {
        if (a[0].size() != m.a.size()) {
            f_panic("Cannot mul/div Matrix: inconsistent size");
        }
        Matrix ret(a.size(), m.a[0].size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < m.a[0].size(); j++) {
                for (int k = 0; k < a[0].size(); k++) {
                    ret.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }
        return ret;
    }

    std::vector<T>& operator[](int i) {
        return a[i];
    }
};
