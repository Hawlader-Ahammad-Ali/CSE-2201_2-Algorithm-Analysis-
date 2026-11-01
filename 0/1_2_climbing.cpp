#include<bits/stdc++.h>
using namespace std;
int climbing_stair(int n)
{
    vector<int>dp(n+3,INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 2 ; i<= n; i++)
    {
        dp[i] = min(dp[i],min(1+dp[i-1] , 1+dp[i-2]));
        //dp[i] = min(dp[i],1+dp[i-2]);
    }
    return dp[n];
}
int main()
{
   int n ;
   cin >> n ;
   cout << climmbing_stair(n);
}

