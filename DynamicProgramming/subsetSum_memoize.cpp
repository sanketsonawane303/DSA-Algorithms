#include<bits/stdc++.h>

using namespace std;

bool subsetSumMemoize(int *arr,int n, int sum){

    if(sum == 0)
        return true;
    if(sum == 0 and n == 0)
        return true;
    if(sum != 0 and n == 0)
        return false;

    if(arr[n-1] <=sum)
        return subsetSumMemoize(arr, n-1, sum-arr[n-1]) or subsetSumMemoize(arr, n-1, sum);
    return subsetSumMemoize(arr, n-1, sum);

}

int main(){
    int arr[] = {5,3,7,13,11,11,33,21,21,33,5,6,8,34,23,23, 23,5,67,87,9,88,77,67,45,667,3,4,23,767,45,42,23,23};
    int sum = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << subsetSumMemoize(arr, n, sum)<<endl;

    return 0;
}