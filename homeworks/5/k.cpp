#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

using namespace std;

int getRepresentableBitCount(int width) {
    if (width == 1) {
        return 7;
    }
    return width * 5 + 1;
}

int findWidth(uint32_t code) {
    int width = 0;
    while (code > 0) {
        code >>= 1;
        ++width;
    }
    return width;
}

string decode(uint32_t code) {
    string decoded;
    int codeBitWidth = findWidth(code);
    int width = 0;
    while (getRepresentableBitCount(width) < codeBitWidth) {
        ++width;
    }
    if (width == 1) {
        decoded += static_cast<char>(code);
        return decoded;
    }

    auto addBlock = [&] (int headerWidth) {
        uint32_t blockMask = ((1 << (8 - headerWidth - 1)) - 1);
        uint32_t blockHeader = ((1 << headerWidth) - 1) << (8 - headerWidth);
        decoded += static_cast<char>((code & blockMask) | blockHeader);
        code >>= (8 - headerWidth - 1);
    };

    for (int i = 0; i < width - 1; ++i) {
        addBlock(1);
    }
    addBlock(width);
    reverse(decoded.begin(), decoded.end());
    return decoded;
}

int main() {
    string result;
    uint32_t code;
    while (cin >> code) {
        result += decode(code);
    }
    cout << result << endl;
    return 0;
}

