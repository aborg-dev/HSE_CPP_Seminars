#include <iostream>
#include <numeric>
#include <array>

using namespace std;

string transformString(const string& s) {
    string transformed;
    for (char c : s) {
        if (isalpha(c)) {
            transformed += tolower(c);
        }
    }
    return transformed;
}

bool isPalindrome(const string& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << (isPalindrome(transformString(s)) ? "YES" : "NO") << endl;
    return 0;
}
