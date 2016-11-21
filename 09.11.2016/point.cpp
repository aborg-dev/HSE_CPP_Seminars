#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Vector {
    double length() const {
        return sqrt(x * x + y * y);
    }

    Vector(int x_, int y_) {
        x = x_;
        y = y_;
    }

    int x = 0;
    int y = 0;
};

Vector operator + (const Vector& lhs, const Vector& rhs) {
    return Vector{lhs.x + rhs.x, lhs.y + rhs.y};
}

Vector operator - (const Vector& lhs, const Vector& rhs) {
    return Vector{lhs.x - rhs.x, lhs.y - rhs.y};
}

double distance(const Vector& p1, const Vector& p2) {
    return (p1 - p2).length();
}

double innerProduct(const Vector& p1, const Vector& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

int main() {
    cout << distance(Vector(1, 1), Vector(2, 2)) << endl;
    return 0;
}
