#include <bits/stdc++.h>
using namespace std;

int rod_cutting(vector<int> &profit, int length)
{
  int n = profit.size();

  vector<vector<int>> dp(n + 1, vector<int>(length + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= length; j++)
    {
      dp[i][j] = dp[i - 1][j];

      if (i <= j)
        dp[i][j] = max(dp[i - 1][j],
                       profit[i - 1] + dp[i][j - i]);
    }
  }

  // Backtracking
  int i = n, j = length;

  while (i > 0 && j > 0)
  {
    if (dp[i][j] == dp[i - 1][j])
      i--;
    else
    {
      cout << i << " ";
      j -= i;
    }
  }

  cout << endl;

  return dp[n][length];
}

int main()
{
  int n, length;
  cin >> n >> length;

  vector<int> profit(n);

  for (int i = 0; i < n; i++)
    cin >> profit[i];

  cout << "Maximum Profit: "<< rod_cutting(profit, length)<<endl;

  return 0;
}
/*
4 4              
2 5 7 8
*/
