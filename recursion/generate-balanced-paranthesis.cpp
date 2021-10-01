#include <iostream>
#include <vector>
#include <string>
using namespace std;

// generate all possible strings containing balanced paranthesis of size 2n

void solve(int o, int c, int n, string temp, vector<string> &result) {
    if (c == n)
        result.push_back(temp);
    else {
        if (o < n)
            solve(o+1, c, n, temp+'(', result);
        if (c < o)
            solve(o, c+1, n, temp+')', result);
    }
}

int main() {
    vector<string> res;
    solve(0, 0, 3, "", res);
    for (string s: res) cout << s << "\n";
    return 0;
}
