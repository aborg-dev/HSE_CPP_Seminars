#include <iostream>
#include <queue>

using namespace std;

const int DEFAULT_LINE_COUNT = 10;

void readOptions(int& lineCount) {
    string options;
    getline(cin, options);
    if (options.empty()) {
        return;
    }
    if (options.substr(0, 2) == "-n") {
        lineCount = stoi(options.substr(3));
    }
}

int main() {
    int lineCount = DEFAULT_LINE_COUNT;
    readOptions(lineCount);
    string line;
    queue<string> lastLines;
    while (getline(cin, line)) {
        lastLines.push(line);
        if (lastLines.size() > lineCount) {
            lastLines.pop();
        }
    }
    while (!lastLines.empty()) {
        cout << lastLines.front() << endl;
        lastLines.pop();
    }
    return 0;
}
