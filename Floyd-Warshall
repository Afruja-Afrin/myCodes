//CSES-1672
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define infLL 1000000000000000000

int main( )
{
    ll dist[ 501][ 501];
    int n, m, q, u, v, w, i, j, k;
    cin >> n >> m >> q;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[ i][ j] = infLL;
        }
    }
    for(i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        if(dist[ u][ v] > w)
        {
            dist[ u][ v] = w;
            dist[ v][ u] = w;
        }
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if((dist[ i][ k] + dist[ k][ j]) < dist[ i][ j])
                {
                    dist[ i][ j] = dist[ i][ k] + dist[ k][ j];
                }
            }
        }
    }

    while(q--)
    {
        cin >> u >> v;
        if(dist[ u][ v] == infLL)
            cout << "-1\n";
        else
            cout << dist[ u][ v] << endl;
    }

    return 0;
}
