#include<bits/stdc++.h>

using namespace std;

vector<int> subsetSum(vector<int> input, int sum){
    int n = input.size();
    bool t[n+1][sum+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0){
                t[i][j] = true;
            }
            if(i==0){
                t[i][j] = false;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(input[i-1] <= j)
                t[i][j] = t[i-1][j-input[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    vector<int> ans;

    for(int i=0; i<=(sum)/2; i++){
        cout << t[n][i] << " ";
    }
    cout << t[n][sum] <<endl;
    return ans;
}

int main(){
    vector<int> input={1,2,7};
    int range = 0;
    for(int i=0; i<input.size(); i++){
        range += input[i];
    }

    vector<int> ans = subsetSum(input, range);

    int mn = INT_MAX;
    for(int i=0; i<ans.size(); i++){
       cout << ans[i] << " ";
    }

    //cout << mn << endl;
    return 0;
}