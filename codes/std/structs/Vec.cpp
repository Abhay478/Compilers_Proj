#include <vector>
template<typename T> 
struct Vec {
    std::vector<T> a;
    Vec() {}
    Vec(int n) : a(std::vector<T>(n)) {}
    Vec(const std::vector<T> a_) {
        a = a_;
    }

    static Vec zero(int n) {
        return Vec(n);
    }

    Vec operator+(const Vec m) const {
        if(a.size() != m.a.size()) {
            f_panic("Cannot add/sub Vec: inconsistent size");
        }
        Vec ret(a.size());
        for(int i = 0; i < a.size(); i++) {
            ret.a[i] = a[i] + m.a[i];
        }
        return ret;
    }

    Vec operator-() const {
        Vec ret(a.size());
        for (int i = 0; i < a.size(); i++) {
            ret.a[i] = -a[i];
        }
        return ret;
    }

    Vec operator*(const T m) const {
        Vec ret(a.size());
        for (int i = 0; i < a.size(); i++) {
            ret.a[i] = a[i] * m;
        }
        return ret;
    }

    T& operator[](int i) {
        return a[i];
    }
};
template<typename T>
Vec<T> operator*(const T m, const Vec<T> v) {
    Vec<T> ret(v.a.size());
    for (int i = 0; i < v.a.size(); i++) {
        ret.a[i] = v.a[i] * m;
    }
    return ret;
}