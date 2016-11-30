#include <iostream>

using namespace std;

template<int N>
int fib() {
    return fib<N - 2>() + fib<N - 1>();
}

template<>
int fib<0>() {
    return 1;
}

template<>
int fib<1>() {
    return 1;
}

int main() {
    cout << fib<1000>() << endl;
    return 0;
}


