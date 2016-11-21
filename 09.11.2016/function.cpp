#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

int max2(int a, int b) {
    return a < b ? b : a;
}

void mySwap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << max2(x, y) << endl;

    cout << x << " " << y << endl;
    mySwap(x, y);
    cout << x << " " << y << endl;
    return 0;
}
