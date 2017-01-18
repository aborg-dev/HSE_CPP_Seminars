#include <iostream>
#include <cstdint>

using namespace std;

int computeLength(uint16_t n) {
    int length = 0;
    while (n) {
        n >>= 1;
        ++length;
    }
    return length;
}

uint16_t computeMaxShift(uint16_t n) {
    auto bitLength = computeLength(n);
    auto maxBit = (1 << bitLength);
    auto maxShift = n;
    for (int i = 0; i < bitLength; ++i) {
        n <<= 1;
        if (n & maxBit) {
            n -= maxBit;
            n += 1;
        }
        maxShift = max(maxShift, n);
    }
    return maxShift;
}

int main() {
    uint16_t n;
    cin >> n;
    cout << computeMaxShift(n) << endl;
    return 0;
}
