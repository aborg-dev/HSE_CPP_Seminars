#include <iostream>
#include <map>

using namespace std;

void printFrequencies(map<char, int> frequencies) {
    int maxFrequency = 0;
    for (const auto& p : frequencies) {
        maxFrequency = max(maxFrequency, p.second);
    }

    for (int line = 0; line < maxFrequency; ++line) {
        for (const auto& p : frequencies) {
            int frequency = p.second;
            if (line >= maxFrequency - frequency) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (const auto& p : frequencies) {
        cout << p.first;
    }
    cout << endl;
}

int main() {
    string line;
    map<char, int> charFrequency;
    while (cin >> line) {
        for (char c : line) {
            ++charFrequency[c];
        }
    }

    printFrequencies(charFrequency);
    return 0;
}

