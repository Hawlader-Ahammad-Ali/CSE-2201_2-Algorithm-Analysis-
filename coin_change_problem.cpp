#include<bits/stdc++.h>
using namespace std;
vector<int>dp(200,INT_MAX);

void coinChange(vector<int>&coin , int amount)
{
    dp[0] = 0 ;
    for(int i = 1 ; i <= amount ; i++)
    {
        for(auto c : coin)
         dp[i] = min(dp[i],1+dp[i-c]);
    }
}
int main()
{
    int n ;
    cin >> n ;
    vector<int>coin(n);
    for(int i = 0 ; i < n ; i++)
        cin >> coin[i];

    int amount ;
    cin >> amount;
    coinChange(coin,amount);
    cout << dp[amount] << endl;
}
