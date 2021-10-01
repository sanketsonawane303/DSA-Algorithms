#include <iostream>
using namespace std;

/*
    find no. of ways to climb 'n' stairs 
    while covering atmost 2 steps in one move
*/

int ways(int x, int n) {
    if (x == n) return 1;
    if (x > n) return 0;
    
    return ways(x+1, n) + ways(x+2, n);
}


int main() {
    cout << ways(0, 4);
    return 0;
}
