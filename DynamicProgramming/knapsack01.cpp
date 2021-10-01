#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> wt, vector<int> val,int w, int n){
    //base case
    if(n<0 or w<=0){
        return 0;
    }

    if(wt[n-1]<=w){
        return max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    }

    return knapsack(wt, val, w, n-1);

}

int main(){
    vector<int> wt = {1,2,3,4,5};
    vector<int> val = {1,2,3,4,5};
    int n = 5;
    int w = 10;
    cout << knapsack(wt, val, w, n);

    return 0;
}