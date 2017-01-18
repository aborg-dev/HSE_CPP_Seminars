#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s[2];
    for (int i = 0; i < 2; ++i) {
        getline(cin, s[i]);
        reverse(s[i].begin(), s[i].end());
    }
    size_t i = 0;
    while (i < min(s[0].size(), s[1].size()) && s[0][i] == s[1][i]) {
        ++i;
    }
    cout << i << endl;
    return 0;
}
