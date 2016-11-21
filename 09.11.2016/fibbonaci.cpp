#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(5) << endl;
    return 0;
}
