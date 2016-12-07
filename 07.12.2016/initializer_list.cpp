#include <iostream>

using namespace std;

struct NoDefaultConstructor
{
    NoDefaultConstructor(int x): x(x)
    { }

    int x;
};

struct Foo
{
    Foo()
        : weird(42)
    { }

    NoDefaultConstructor weird;
};

int main() {
    Foo f;
}
