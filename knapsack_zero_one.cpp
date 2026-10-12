#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;

int Knapsack(vector<int>&weight , vector<int>&value , int w , int n)
{
    if(w == 0 || n == 0) return 0 ;
    int taken = value[n-1] + Knapsack(weight , value , w - weight[n-1] , n -1);
    int skip = Knapsack(weight , value , w  , n -1);
    int mx = max(skip , taken);
    return mx ;
}
int main()
{
   int n , w ;
   cin >> n >> w;
   vector<int>value(n+1) , weight(n+1);
   for(int i = 1 ;  i <= n ; i++)
    cin >> weight[i] ;
      for(int i = 1 ;  i <= n ; i++)
    cin >> value[i];
   cout << "Maximum profit = " << Knapsack(weight , value , w , n) << endl;
}
