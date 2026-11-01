#include<bits/stdc++.h>
using namespace std;
int rod_cutting(vector<int>&profit , int length)
{
    int n = length;
    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= n;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(i < j)
            dp[i][j] = max(dp[i-1][j] ,profit[i] + dp[i][j-i-1]);
        }
    }
    int i = n , j = n;
    while(i > 0 && j >0) 
    {
        if(dp[i][j] == dp[i-1][j])
            i--;
        else{
            cout << i << " ";
            j -= i;
        }
    }
    cout << endl;
    return dp[n][length];
}
int main()
{
    int n , m , length;
    cin >> n  >> length;
    vector<int>profit(n),position(n);
    for(int i = 0 ; i< n ; i++)
    {
        cin >> position[i] >> profit[i];
    }
    cout <<  rod_cutting(profit,position,length);
}
/*
4 
2 5 7 8
*/
