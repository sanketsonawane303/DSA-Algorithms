#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> wt, vector<int> val,int w, int n, int v[6][11]){
    //base case
    if(n<0 or w<=0){
        return 0;
    }
    if(v[n][w] != -1)
        return v[n][w];

    if(wt[n-1]<=w){
        return v[n][w]= max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1, v), knapsack(wt, val, w, n-1, v));
    }

    return v[n][w]= knapsack(wt, val, w, n-1, v);

}

int main(){

    vector<int> wt = {1,2,3,4,5};
    vector<int> val = {1,2,3,4,5};
    int n = 5;
    int w = 10;
    int v[6][11]; // matrix for memoization
    memset(v, -1, sizeof(v));// setting all values to -1


    cout << knapsack(wt, val, w, n, v)<<endl;

    return 0;
}