#include <iostream>

using namespace std;

void generateStrings(int n, int k, string& s)
{
    cout << s << endl;
    if (k == n) {
        return;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        s += c;
        generateStrings(n, k + 1, s);
        s.pop_back();
    }
}

void generateStrings(int n) {
    string s;
    generateStrings(n, 0, s);
}

int main() {
    int n;
    cin >> n;
    generateStrings(n);
}
