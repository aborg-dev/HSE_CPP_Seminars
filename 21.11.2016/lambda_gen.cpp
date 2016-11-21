#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    std::function<void(int, int, string)> generateSequence = [&] (int n, int k, string s) {
        if (n == k) {
            cout << s << endl;
            return;
        }
        generateSequence(n, k + 1, s + "0");
        generateSequence(n, k + 1, s + "1");
    };

    generateSequence(n, 0, "");
}
