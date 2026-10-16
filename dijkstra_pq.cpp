#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;

vector<int>dijkstra (vector<vector<pair<int,int>>>&adj , int n,int source)
{
    vector<int>dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.emplace(0,source);
    dist[source] =  0;
    while(!pq.empty())
    {
        auto p = pq.top();
        int d = p.first;
        int u = p.second;
        pq.pop();
        if( d > dist[u] ) continue;

        for(auto &ed : adj[u])
        {
            int v = ed.first;
            int w = ed.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u]+w;
                pq.emplace(dist[v],v);
            }
        }
    }
    return dist ;

}
int main()
{
    int n , e ;
    cin >> n >> e;
    vector<vector<pair<int,int>>>adj(n);
    for(int i = 0 ; i < e ; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source ;
    cin >> source ;
    vector<int>dist = dijkstra(adj,n,source);
    for(int i = 0 ; i < n ; i++)
    {
        cout << source << " -> " << i << " " << dist[i] << endl;
    }
}
/*
6 9
0 1 4
0 2 4
1 2 2
1 3 5
2 3 1
2 4 6
3 4 3
3 5 7
4 5 2
0
*/
