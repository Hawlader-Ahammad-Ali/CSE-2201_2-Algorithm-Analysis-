#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int minKey(vector<bool>visited , vector<int>weight)
{
    int mn = INF;
    int idx  = -1 ;
    for(int i = 0 ; i < visited.size() ; i++)
    {
        if(weight[i] < mn && !visited[i])
           {
               mn = weight[i];
               idx = i;
           }
    }
    return idx;
}
void printMST(vector<vector<int>>&graph , vector<int>&parent)
{
    cout << "MST " << endl;
    for(int i = 1 ; i < parent.size() ; i++ )
    {
        cout << parent[i] << "-" << i << " Weight : " << graph[parent[i]][i] << endl;
    }
}

void primMST (vector<vector<int>>&adj  , int n )
{
    vector<bool>visited(n , false);
    vector<int>key(n,INF);
    vector<int>parent(n);
    parent[0] = -1;
    key[0] = 0;
    for(int i = 0 ; i < n-1  ; i++)
    {
        int u = minKey(visited,key);
        visited[u] = true;
        for(int v = 0 ; v < n ; v++)
        {
            if(key[v] > adj[u][v] && !visited[v])
            {
               // visited[v] = true;
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    printMST( adj , parent);
}

int main()
{
    cout << "Enter The node and edge " << endl;
    int n , e ;
    cin >> n >> e;
    vector<vector<int>>adj(n,vector<int>(n,INF));
   for(int i = 0 ; i < e ; i++)
   {
       int u , v , w;
       cin >> u >> v >> w;
       adj[u][v] = w;
       adj[v][u] = w;
   }
    primMST(adj,n);
}
