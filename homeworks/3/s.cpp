#include <iostream>
#include <vector>

using namespace std;

bool possible_to_pay(int n, int k, std::vector<int>& coins) {
    if (n == 0) {
        return true;
    }
    if (k == coins.size()) {
        return false;
    }
    for (int take = 0; take <= 2; ++take) {
        int nextN = n - take * coins[k];
        if (nextN >= 0 && possible_to_pay(nextN, k + 1, coins)) {
            return true;
        }
    }
    return false;
}

bool possible_to_pay(int n, std::vector<int>& coins) {
    return possible_to_pay(n, 0, coins);
}

int main() {
    return 0;
}
