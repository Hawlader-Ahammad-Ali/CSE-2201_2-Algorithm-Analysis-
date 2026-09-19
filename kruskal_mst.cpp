// 2307070
// sajib_70

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct Edge
{
    int u ,  v, w;
};
bool compare(Edge a , Edge b)
{
    return a.w < b.w ;
}
class DSU
{
public:
    vector<int>parent , rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i <  n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        return (parent[i] == i ) ? i : (parent[i] = find(parent[i]));
    }
    void merge(int x , int y)
    {
        int u = find(x);
        int v = find(y);
        if(u == v) return;
        if (rank[u]< rank[v])
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else
        {
            parent[u] = v;
            rank[u]++;
        }
    }

};
void kruskal(vector<Edge>&Edges , int n)
{
    sort(Edges.begin(),Edges.end(),compare);
    DSU dsu(n);
    vector<Edge>mst ;
    int cnt  = 0 , value = 0;
    for(auto ed : Edges)
    {
        int u = ed.u , v = ed.v , weight = ed.w;
        int x = dsu.find(u) , y = dsu.find(v);
        if( x != y)
        {

            dsu.merge(x,y);
            mst.push_back(ed);
            value += weight;
            cnt++;
            if(cnt == n -1)
                break;
        }
    }
    cout << "Total MST cost : " << value << endl;
    for(int i = 0 ; i < mst.size() ; i++)
    {
        cout << mst[i].u << " - " << mst[i].v << " -> " << mst[i].w << endl;
    }
    return ;
}
int main()
{
    cout << "Enter The node and edge " << endl;
    int n , e ;
    cin >> n >> e;
   vector<Edge>Edges(e);
   for(int i = 0 ; i < e ; i++)
   {
       cin >> Edges[i].u >> Edges[i].v >> Edges[i].w;
   }
   kruskal(Edges,n);
}
