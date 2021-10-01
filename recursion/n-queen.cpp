#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool safe(int i, int j, vector<string> &v) {
    int x, y;

    x = i - 1;
    y = j;
    while (x >= 0) {
        if (v[x][y] == 'Q') return false;
        x--;
    }

    x = i - 1;
    y = j - 1;
    while (x >= 0 && y >= 0) {
        if (v[x][y] == 'Q') return false;
        x--; y--;
    }

    x = i - 1;
    y = j + 1;
    while (x >= 0 && y < v.size()) {
        if (v[x][y] == 'Q') return false;
        x--; y++;
    }

    return true;
}

void solve(int i, vector<string> &v) {
    if (i == v.size()) {
        // print the chess board
        for (string row: v) cout << row << "\n";
        cout << "\n\n";

        return;
    }

    for (int j = 0; j < v[i].size(); j++) {
        if (safe(i, j, v)) {
            v[i][j] = 'Q';
            solve(i+1, v);
            v[i][j] = '.';
        }
    }
}

int main() {
    // chessboard
    vector<string> v = {".....", ".....", ".....", ".....", "....."}; 
    solve(0, v);
    return 0;
}
