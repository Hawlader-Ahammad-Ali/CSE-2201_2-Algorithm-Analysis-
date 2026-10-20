#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double INF = 1e5;

void FloydWarshall(int mat[][20], int n )
{
    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(mat[i][j] > mat[i][k] + mat[k][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
}
int main()
{
    int n, e ;
    cin >> n >> e ;
    int mat[20][20] = {INF};
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
            if(i == j)
                mat[i][i] = 0;
            else
                mat[i][j] = INF;
    }
    for(int i = 0 ; i < e ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    FloydWarshall(mat,n);

    cout << "All pair shortest path Matrix  : " << endl;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
/*
5 10
1 2 4
1 4 5
2 5 6
2 3 1
3 1 2
3 4 3
4 3 1
4 5 2
5 4 4
5 1 1
*/
