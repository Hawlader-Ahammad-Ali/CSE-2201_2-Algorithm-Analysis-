#include<bits/stdc++.h>
using namespace std;
vector<int>dp(200,INT_MAX);
int rodCutting(vector<int>&profit,int i)
{
    if(i == 0) return 0;
    int result = 0;
    for(int j = 1 ; j <= i;j++)
    {
        result = max(result,profit[j] + rodCutting(profit,i-j));
    }
    return result;
}
int main()
{
    int n ;
    cin >> n ;
    vector<int>profit(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin >> profit[i];
    cout << "Max profit = " << rodCutting(profit,n) << endl;
}
/*
8
1 5 8 9 10 17 17 20
*/
