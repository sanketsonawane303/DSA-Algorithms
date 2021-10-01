#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
 
    int n = a.length();
    int m = b.length();
 
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j] = 100000;
        }
    }  
 
    for(int i=0;i<m;i++)
    {
        dp[0][i] = i;
    }
 
    for(int i=0;i<n;i++)
    {
        dp[i][0] = i;
    }
 
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
 
            // if chars are equal
            if(a[i-1] == b[j-1])
                dp[i][j] = min({dp[i][j],dp[i-1][j-1]});
 
 
            // add one character
            dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
 
            // remove one character
            dp[i][j] = min({dp[i][j],dp[i-1][j]+1});
 
            // replace
            dp[i][j] = min({dp[i][j],dp[i-1][j-1]+1});
        }
    }
 
    cout << dp[n][m];
}
