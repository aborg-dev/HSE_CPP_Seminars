#include <iostream>
#include <vector>

template <typename T>
class MathVector {
 private:
    std::vector<T> data;

 public:
    // Zero vector of size n
    MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last): data(first, last) {
    }

    size_t Dimension() const {
         return data.size();
    }

    T& operator[] (size_t i) {
        return data[i];
    }

    const T& operator[] (size_t i) const {
        return data[i];
    }
};


// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i < v.Dimension(); ++i) {
        if (i > 0)
            out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator *= (MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i < v.Dimension(); ++i)
        v[i] *= scalar;
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

template <typename T>
MathVector<T>& operator += (MathVector<T>& a, const MathVector<T> b) {
    for (int i = 0; i < a.Dimension(); ++i) {
        a[i] += b[i];
    }
    return a;
}

template <typename T>
MathVector<T> operator + (const MathVector<T>& a, const MathVector<T> b) {
    auto res(a);
    return res += b;
}

/*
int main() {
    MathVector<int> v(3);
    std::cout << "omg" << std::endl;
    return 0;
}
*/
