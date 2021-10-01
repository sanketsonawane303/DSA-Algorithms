#include <iostream>
using namespace std;

/*
    alice and bob play a game. there is a no. 'n' on the board.
    in 1 move, a player can replace n by n-x such that 0< x < n and n%x = 0.
    game ends when a player has no moves left (ie. n = 1) and he/she loses.
    if alice starts first, find if she can win?
*/

bool game(int n) {
    // if n = 1, player loses
    if (n == 1) return false;

    for (int x = 1; x < n; x++)
        if (n % x == 0) {
            // check of other player loses on n-x, then current player wins
            if (game(n - x) == false) return true;
        }
    
    // if no x allows to win, then we lose
    return false;
}

int main() {
    cout << game(4);
    return 0;
}
