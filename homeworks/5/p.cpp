#include <iostream>

using namespace std;

class Rational
{
public:
    Rational(int x = 0, int y = 1): x(x), y(y)
    { }

private:
    int x;
    int y;
};

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.x * rhs.x, lhs.y * rhs.y);
}

ostream& operator << (ostream& os, const Rational& r) {
    os << r.x << "/" << r.y;
    return os;
}

int main() {
    Rational one(1, 1);
    Rational two(2, 1);
    cout << one << endl;
    cout << two << endl;
    cout << two * two << endl;
    cout << 10 * two << endl;
    cout << two * 10 << endl;
    return 0;
}
