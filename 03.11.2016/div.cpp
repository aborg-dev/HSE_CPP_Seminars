#include <iostream>

using namespace std;

int getRemainder(int x, int mod) {
    x %= mod;
    if (x < 0) {
        x += mod;
    }
    return x;
}

int main()
{
    cout << getRemainder(-5, 3) << endl;
    return 0;
}
