#include <iostream>

using namespace std;

unsigned int make_bits_equal(unsigned int x, size_t i, size_t j) {
    if (x & (1 << j)) {
        return x | (1 << i);
    } else {
        return x & (~(1 << i));
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        unsigned int x;
        size_t a, b;
        cin >> x >> a >> b;
        cout << make_bits_equal(x, a, b) << endl;
    }
    return 0;
}
