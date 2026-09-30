#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &rGraph, int src, int sink,vector<int> &parent , int n)
{
     vector<bool>visited(n,false);
     queue<int>pq;
     pq.push(src);
     visited[src] = true;
     parent[src] = -1;
     while(!pq.empty())
     {
         int u = pq.front();
         pq.pop();
         for(int v = 0 ; v < n  ; v++)
         {
             if(!visited[v] && rGraph[u][v] > 0)
             {
                 visited[v] = true;
                 parent[v] = u;
                 if(v == sink) return true ;
                 pq.push(v);
             }
         }
     }
     return false;
}
void findMaxFlow(int n, vector<vector<int>> &edges)
{
    vector<vector<int>>rgraph = edges ;
    int source = 0 ;
    int sink = n-1;
    vector<int>parent(n);
    int maxFlow = 0 ;
    while(bfs(rgraph,source , sink , parent, n))
    {
        int bottleneck = INT_MAX;
        for(int v = sink ; v != source ; v = parent[v])
        {
            int u = parent[v];
            bottleneck = min(bottleneck,rgraph[u][v]);
        }
        for(int v = sink ; v != source ; v = parent[v])
        {
            int u = parent[v] ;
            rgraph[u][v] -=bottleneck;
            rgraph[v][u] +=bottleneck;
        }
        maxFlow += bottleneck;
    }
    cout << maxFlow << endl;
}
int main()
{
    int n, e;
    cin >>  n >> e;
    vector<vector<int>>graph(n,vector<int>(n,0));
    for(int i = 0 ; i < e ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    findMaxFlow(n, graph);
}
/*
6 9
0 1 16
0 2 13
1 3 12
3 5 21
2 1 4
2 4 14
4 3 9
3 2 9
4 5 4
*/
