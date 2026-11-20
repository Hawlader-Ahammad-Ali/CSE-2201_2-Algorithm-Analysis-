#include<bits/stdc++.h>
using namespace std;
int numOfWays(int n)
{
   vector<int> dp(n + 1, 0);
   dp[0] = dp[1] = 1;
   int i = 2;
   while(i <= n)
   { 
         dp[i] = dp[i - 1] + dp[i - 2];
         i++;
   }
   return dp[n];
}

int main()
{
    int n ;
    cin >> n ;
    cout << "Number of ways to reach the " << n << " is =  " << numOfWays(n) << endl;
}
