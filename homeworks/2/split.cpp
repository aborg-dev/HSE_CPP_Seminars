#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> parts;
    string currentPart;
    for (int i = 0; i <= s.length(); ++i) {
        if (i == s.length() || s[i] == delimiter) {
            parts.push_back(currentPart);
            currentPart = "";
        } else {
            currentPart += s[i];
        }
    }
    return parts;
}

int main() {
    string s;
    char delimiter;
    getline(cin, s);
    cin >> delimiter;
    for (const auto& part : split(s, delimiter)) {
        cout << part << endl;
    }
    return 0;
}

