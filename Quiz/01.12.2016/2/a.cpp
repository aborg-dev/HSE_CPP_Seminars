#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

void readCommandOptions(bool& shouldReverse) {
    string line;
    getline(std::cin, line);
    shouldReverse = (line.find("-r") != string::npos);
}

vector<string> readLines() {
    string line;
    vector<string> strings;
    while (getline(std::cin, line)) {
        strings.push_back(line);
    }
    return strings;
}

void printLines(const vector<string>& lines) {
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}

int main() {
    bool shouldReverse = false;
    readCommandOptions(shouldReverse);
    auto strings = readLines();
    sort(strings.begin(), strings.end());
    if (shouldReverse) {
        std::reverse(strings.begin(), strings.end());
    }
    printLines(strings);
    std::cout << "Hello, world" << std::endl;
    return 0;
}
