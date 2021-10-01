#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    find minimum cost to climb 'n' stairs
    while covering atmost 2 steps in one move
*/

int minCost(int i, int n, vector<int> cost) {
    if (i == n - 1) return cost[n-1];

    int c = minCost(i+1, n, cost);
    if (i+2 < n)
        c = min(c, minCost(i+2, n, cost));
    
    return cost[i] + c;
}


int main() {
    vector<int> cost = {5, 10, 100, 10, 5};
    int n = cost.size();
    cout << min(minCost(0, n, cost), minCost(1, n, cost));
    return 0;
}
