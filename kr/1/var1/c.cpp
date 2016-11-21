#include <iostream>
#include <vector>

using namespace std;

string join(const vector<string>& tokens, char delimiter) {
    string joined;
    for (int i = 0; i < tokens.size(); ++i) {
        if (i > 0) {
            joined += delimiter;
        }
        joined += token;
    }
    return joined;
}

/*
int main() {
    int tokenCount;
    cin >> tokenCount;
    vector<string> tokens(tokenCount);
    for (int i = 0; i < tokenCount; ++i) {
        cin >> tokens[i];
    }
    char delimiter;
    cin >> delimiter;
    cout << join(tokens, delimiter) << endl;
    return 0;
}
*/
