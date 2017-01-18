#include <iostream>
#include <ostream>
#include <vector>

using std::vector;

template <typename T>
int Sign(T x) {
    if (x == 0) {
        return 0;
    }
    return x > 0 ? +1 : -1;
}

template <typename T>
class Polynomial {
 public:
    using Underlying = std::vector<T>;
    using const_iterator = typename Underlying::const_iterator;

    Polynomial(const vector<T>& coefficients_)
        : coefficients(coefficients_) {
        trimLeadingZeroes();
    }

    Polynomial(const T& value = T())
        : coefficients({value}) {
        trimLeadingZeroes();
    }

    template <typename It>
    Polynomial(It first, It last)
        : coefficients(first, last) {
        trimLeadingZeroes();
    }

    const_iterator begin() const {
        return coefficients.cbegin();
    }

    const_iterator end() const {
        return coefficients.cend();
    }

    T operator[] (size_t index) const {
        if (index >= coefficients.size()) {
            return T();
        }
        return coefficients[index];
    }

    // P(x) = a0 + a1 x^1 + a2 x^2 + a3 x^3 = a0 + x (a1 + x (a2 + x (a3)))
    T operator() (const T& x) const {
        if (coefficients.size() == 0) {
            return 0;
        }

        T result = T();
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            result *= x;
            result += coefficients[i];
        }
        return result;
    }

    int Degree() const {
        if (coefficients.size() == 0) {
            return -1;
        }
        return coefficients.size() - 1;
    }

    Polynomial<T>& operator += (const Polynomial<T>& rhs) {
        return multiplyAndAdd(rhs, +1);
    }

    Polynomial<T>& operator -= (const Polynomial<T>& rhs) {
        return multiplyAndAdd(rhs, -1);
    }

    friend Polynomial<T> operator + (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
        Polynomial<T> result = lhs;
        result += rhs;
        return result;
    }

    friend bool operator == (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
        return lhs.coefficients == rhs.coefficients;
    }

    friend Polynomial<T> operator * (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
        int degree = lhs.Degree() + 1 + rhs.Degree() + 1;
        vector<T> result(degree + 1, T());
        for (int i = 0; i < lhs.Degree() + 1; ++i) {
            for (int j = 0; j < rhs.Degree() + 1; ++j) {
                result[i + j] += lhs[i] * rhs[j];
            }
        }
        return Polynomial<T>(result);
    }

    friend Polynomial<T> operator / (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
        return divideWithRemainder(lhs, rhs).first;
    }

    friend Polynomial<T> operator % (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
        return divideWithRemainder(lhs, rhs).second;
    }

    Polynomial<T>& operator /= (const Polynomial<T>& rhs) {
        *this = divideWithRemainder(*this, rhs).first;
        return *this;
    }

    Polynomial<T>& operator %= (const Polynomial<T>& rhs) {
        *this = divideWithRemainder(*this, rhs).second;
        return *this;
    }

    friend std::pair<Polynomial<T>, Polynomial<T>> divideWithRemainder(
        Polynomial<T> lhs,
        const Polynomial<T>& rhs) {
        int degree = std::max(lhs.Degree() - rhs.Degree(), -1);
        vector<T> result(degree + 1, T());
        for (int i = 0; i < degree + 1; ++i) {
            int lhsPos = lhs.Degree() - i;
            int rhsPos = rhs.Degree();
            int resultPos = degree - i;
            result[resultPos] = lhs[lhsPos] / rhs[rhsPos];
            for (int j = 0; j < rhs.Degree() + 1; ++j) {
                lhs.coefficients[lhsPos - j] -= rhs[rhsPos - j] * result[resultPos];
            }
        }
        lhs.trimLeadingZeroes();
        return std::make_pair(Polynomial<T>(result), lhs);
    }

    Polynomial<T> power(int exponent) {
        Polynomial<T> result(1);
        for (int i = 0; i < exponent; ++i) {
            result *= *this;
        }
        return result;
    }

    friend Polynomial<T> operator & (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
        Polynomial<T> result;
        Polynomial<T> rhsPow(1);
        for (int i = 0; i < lhs.Degree() + 1; ++i) {
            result += lhs[i] * rhsPow;
            rhsPow *= rhs;
        }
        return result;
    }

    Polynomial<T>& operator *= (const Polynomial<T>& rhs) {
        auto result = *this * rhs;
        *this = result;
        return *this;
    }

    friend Polynomial<T> operator , (Polynomial<T> lhs, Polynomial<T> rhs) {
        while (lhs.Degree() >= 0) {
            std::swap(lhs, rhs);
            lhs %= rhs;
        }
        rhs.normalize();
        return rhs;
    }

    void trimLeadingZeroes() {
        while (!coefficients.empty() && coefficients.back() == T()) {
            coefficients.pop_back();
        }
    }

    void normalize() {
        for (auto& coef : coefficients) {
            coef /= coefficients.back();
        }
    }

 private:
    Underlying coefficients;

    Polynomial<T>& multiplyAndAdd(const Polynomial<T>& rhs, T scalar) {
        int maxDegree = std::max(Degree(), rhs.Degree()) + 1;
        coefficients.resize(maxDegree, 0);
        for (int i = 0; i < maxDegree; ++i) {
            coefficients[i] += rhs[i] * scalar;
        }
        trimLeadingZeroes();
        return *this;
    }
};


template <typename T>
bool operator != (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
Polynomial<T> operator - (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    Polynomial<T> result = lhs;
    result -= rhs;
    return result;
}

// -x^3+4*x^2+x-1
template <typename T>
std::ostream& operator << (std::ostream& os, const Polynomial<T>& poly) {
    if (poly.Degree() == -1) {
        os << 0;
        return os;
    }
    bool isFirst = true;
    for (int i = poly.Degree(); i >= 0; --i) {
        int sign = Sign(poly[i]);
        if (sign != 0) {
            T coef = poly[i];
            if (coef * sign != 1 || i == 0) {
                if (sign > 0) {
                    if (!isFirst) {
                        os << "+";
                    }
                }
                os << coef;
            } else {
                if (sign < 0) {
                    os << "-";
                } else {
                    if (!isFirst) {
                        os << "+";
                    }
                }
            }
            isFirst = false;

            if (i > 0) {
                if (coef * sign != 1) {
                    os << "*";
                }
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
        }
    }
    return os;
}

/*
void testPrint() {
    std::cout << Polynomial<int>({7}) << std::endl;
    std::cout << Polynomial<int>({-7}) << std::endl;
    std::cout << Polynomial<int>({0}) << std::endl;
    std::cout << Polynomial<int>(vector<int>({-1, -1})) << std::endl;
    std::cout << Polynomial<int>(vector<int>({+1, -1})) << std::endl;
    std::cout << Polynomial<int>(vector<int>({-1, +1})) << std::endl;
    std::cout << Polynomial<int>(vector<int>({+1, +1})) << std::endl;
    std::cout << Polynomial<int>(vector<int>({0, +1})) << std::endl;
    std::cout << Polynomial<int>(vector<int>({0, -1})) << std::endl;
    std::cout << Polynomial<int>(vector<int>({0, -2, -2})) << std::endl;
    std::cout << Polynomial<int>({-7, 0, -5, 3}) << std::endl;
    std::cout << Polynomial<int>({0, 0, 3}) << std::endl;
    std::cout << Polynomial<int>({1, -3, 3}) << std::endl;
    std::cout << Polynomial<int>({1, -1, 1}) << std::endl;
}

void testConstructors() {
    Polynomial<int> p = 1;
    std::cout << p << std::endl;
    std::cout << Polynomial<int>() << std::endl;
    std::cout << Polynomial<int>(42) << std::endl;
    vector<int> coef = {3, 2};
    std::cout << Polynomial<int>(coef.begin(), coef.end()) << std::endl;
}

void testComparison() {
    std::cout << (Polynomial<int>(3) == Polynomial<int>(4)) << std::endl;
    std::cout << (Polynomial<int>(3) != Polynomial<int>(4)) << std::endl;
}

void testPlusMinus() {
    std::cout << (Polynomial<int>({2}) + 2) << std::endl;
    std::cout << (Polynomial<int>({1, 2, 3}) + Polynomial<int>({4, 5, 6})) << std::endl;
    std::cout << (Polynomial<int>({1, 2, 3}) - Polynomial<int>({4, 5, 6})) << std::endl;
}

void testMultiply() {
    auto a = Polynomial<int>(vector<int>({1, 1}));
    auto poly = a * a;
    std::cout << poly << std::endl;
}

void testEvaluate() {
    auto poly = Polynomial<int>(vector<int>({1, 1, 1}));
    std::cout << poly(3) << std::endl;
}

void testComposition() {
    auto poly = Polynomial<int>(vector<int>({1, 1}));
    std::cout << (poly & poly) << std::endl;
}

void testIterators() {
    Polynomial<int> poly({1, 2, 3});
    for (auto it = poly.begin(); it != poly.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (int coef : poly) {
        std::cout << coef << std::endl;
    }
}

void testDivision() {
    auto a = Polynomial<int>(vector<int>({1, 1, 1, 2}));
    auto b = Polynomial<int>(vector<int>({1, 1}));
    std::cout << (a / b) << ", " << (a % b) << std::endl;
}

void testGCD() {
    std::cout << (Polynomial<int>({1, 1, 1, 1}), Polynomial<int>(vector<int>({1, 1}))) << std::endl;
    std::cout << (Polynomial<int>({1}), Polynomial<int>(vector<int>({0, 1}))) << std::endl;
    std::cout << (Polynomial<int>({1, 1, 1}), Polynomial<int>({1, 1, 1})) << std::endl;
    std::cout << (Polynomial<int>({1}), Polynomial<int>({1, 1, 1})) << std::endl;
    std::cout << (Polynomial<int>({2, 2, 2}), Polynomial<int>({1, 1, 1})) << std::endl;
}

int main() {
    testGCD();
    return 0;
}
*/
