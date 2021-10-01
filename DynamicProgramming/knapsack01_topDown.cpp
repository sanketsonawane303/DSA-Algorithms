#include<bits/stdc++.h>

using namespace std;

int knapsackTopDown(vector<int> wt, vector<int> val, int n, int w){
    int t[n+1][w+1];
    //initialization of matrix with the help of base condition in the reursive solution
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 or j==0)
                t[i][j] = 0;
        }
    }
    // filling rest of the matrix with the help of choice diagram used in recursive approach
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(wt[i-1] <=j)
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);

            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][w];

}

int main(){
    vector<int> wt = {1,2,3,4,5};
    vector<int> val = {1,2,3,4,5};

    cout << knapsackTopDown(wt, val, 5, 10)<<endl;

    return 0;
}