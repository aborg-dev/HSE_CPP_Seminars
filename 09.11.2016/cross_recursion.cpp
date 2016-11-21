#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

void playSecond(int n);

void playFirst(int n) {
    cout << "playFirst(" << n << ")\n";
    if (n == 0) {
        return;
    }
    playSecond(n - 1);
}

void playSecond(int n) {
    cout << "playSecond(" << n << ")\n";
    if (n == 0) {
        return;
    }
    playFirst(n - 1);
}

int main()
{
    playFirst(4);
    return 0;
}
