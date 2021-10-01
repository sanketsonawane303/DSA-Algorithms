#include<bits/stdc++.h>

using namespace std;

bool equalSumPartition(int *arr, int n, int sum){
    bool t[n+1][sum+1];

    for(int i=0;i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
        }
    }

    for(int i=1;i<=n; i++){
        for(int j=1;j<=sum; j++){
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}

int main(){
    int arr[] = {1,2,2,3,1,2,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    cout << equalSumPartition(arr, n, sum/2)<<endl;


    return 0;
}