#include <iostream>
#include <numeric>
#include <array>

using namespace std;

int getCharClass(char c) {
    if ('a' <= c && c <= 'z') {
        return 0;
    }
    if ('A' <= c && c <= 'Z') {
        return 1;
    }
    if ('0' <= c && c <= '9') {
        return 2;
    }
    return 3;
}

bool validPassword(const string& s) {
    if (s.length() < 8 || s.length() > 14) {
        return false;
    }

    vector<bool> hasCharClass(4, false);
    for (char c : s) {
        if (c < 33 || c > 127) {
            return false;
        }
        hasCharClass[getCharClass(c)] = true;
    }
    int charClassCount = std::accumulate(hasCharClass.begin(), hasCharClass.end(), 0);
    return charClassCount >= 3;
}

int main() {
    string s;
    getline(cin, s);
    cout << (validPassword(s) ? "YES" : "NO") << endl;
    return 0;
}
