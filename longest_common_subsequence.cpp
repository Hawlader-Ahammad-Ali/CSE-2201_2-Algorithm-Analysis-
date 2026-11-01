#include<bits/stdc++.h>
using namespace std;
void LCS (int n , int m , string st1 , string st2)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1; j <= m ;j++)
        {
            if(st1[i-1] == st2[j-1])
                dp[i][j] =  1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        }
    }
    string ans = "";

    int i = n, j = m;

    while(i > 0 && j > 0)

    {

        if(st1[i-1] == st2[j-1])

        {

            ans += st1[i-1];

            i--;

            j--;

        }

        else if(dp[i-1][j] > dp[i][j-1])

            i--;

        else

            j--;

    }

    reverse(ans.begin(), ans.end());

    cout << "LCS Length: " << dp[n][m] << endl;

    cout << "LCS String: " << ans << endl;

}
int main()
{
    string st1,st2;
    cin >> st1 >> st2;
    int n = st1.size();
    int m = st2.size();
    LCS(n,m,st1,st2);
}
/*
8
1 5 8 9 10 17 17 20
*/
