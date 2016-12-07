#include <iostream>
#include <vector>

using namespace std;

struct Bar;

struct Foo
{
    Foo() {}

    int operator + (const Bar& b) const {
        return 42;
    }
};

struct Bar
{
    Bar() {}

    int operator + (const Foo& f) {
        return f + *this;
    }
};

int main() {
    Foo f;
    Bar b;
    cout << f + b << endl;
    cout << b + f << endl;
}
