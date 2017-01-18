#include <iostream>
#include <queue>

using namespace std;

using Card = int;

bool compareCards(const Card& lhs, const Card& rhs) {
    if (lhs == 9 && rhs == 0) {
        return true;
    }
    if (lhs == 0 && rhs == 9) {
        return false;
    }
    return lhs < rhs;
}

const int MAX_ITERATION_COUNT = 1000000;

int main() {
    queue<Card> playerCards[2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            int card;
            cin >> card;
            playerCards[i].push(card);
        }
    }
    int iterationsPassed = 0;
    while (!playerCards[0].empty() && !playerCards[1].empty()
           && iterationsPassed < MAX_ITERATION_COUNT) {
        Card cards[2];
        for (int i = 0; i < 2; ++i) {
            cards[i] = playerCards[i].front();
            playerCards[i].pop();
        }
        int winner = 0;
        if (compareCards(cards[0], cards[1])) {
            winner = 1;
        }
        playerCards[winner].push(cards[0]);
        playerCards[winner].push(cards[1]);
        ++iterationsPassed;
    }
    if (iterationsPassed == MAX_ITERATION_COUNT) {
        cout << "botva" << endl;
    } else {
        int winner = 0;
        if (playerCards[0].empty()) {
            winner = 1;
        }
        cout << (winner == 0 ? "first" : "second") << " " << iterationsPassed << endl;
    }
    return 0;
}
