#include<bits/stdc++.h>

using namespace std;

int countSubsetWithGivenSum(int *arr,int n, int sum){
    int t[n+1][sum+1];

    //initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main(){
    int arr[] = {1,2,3,4,5,3};
    int sum = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countSubsetWithGivenSum(arr, n, sum)<<endl;

    return 0;
}