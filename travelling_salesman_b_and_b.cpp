#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double INF = 1e5;

int dfs(vector<vector<int>>&mat,vector<bool>&vis , int last , int curr)
{
    int n = vis.size();
    if(curr == n) return mat[last][0] ;
    int mn = INF;
    for(int i = 1 ; i < n ; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            mn = min(mn , mat[last][i] + dfs(mat,vis,i,curr+1));
            vis[i] = false;
        }
    }
    return mn;
}


int trs(vector<vector<int>>&mat , int n)
{
    vector<bool>vis(n,false);
    vis[0] = true;
    int cost = dfs(mat,vis,0,1);
    return cost ;
}

int main()
{
    int n , e;
    cin >> n >> e;
    vector<vector<int>>mat(n,vector<int>(n,0));
    for(int i = 0 ; i < e ; i++){
        int u , v  , w;
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;
    }
    cout << endl;
    cout << trs(mat,n) << endl;
}
/*
4 6
0 1 10
0 2 15
0 3 20
1 2 35
1 3 25
2 3 30
*/
