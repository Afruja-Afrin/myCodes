//LoghtOJ 1094


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 3e4+5;
vector< int> adj[ mx];
int vis[ mx], res, m[ mx];
map< pair< int, int>, int> cost;

int DFS( int u)
{
    vis[ u] = 1;

    int cnt = 0;
    for(auto v: adj[ u])
    {
        if(vis[ v] == 0)
        {
            cnt++;
            int x = DFS(v);
            res = max( res, m[u]+x+cost[{ u, v}]);
            m[u] = max( m[u], x+cost[{ u, v}]);
        }
    }
    return m[u];
}

int main( )
{
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++)
        {
            vis[i] = 0;
            adj[i].clear( );
            m[i] = 0;
        }
        res = 0;
        n--;
        while(n--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[ u].push_back( v);
            adj[ v].push_back( u);
            cost[ { u, v}] = w;
            cost[ { v, u}] = w;
        }
        int ans = DFS(0);
        cout << "Case " << tc << ": " << res << endl;
    }

    return 0;
}
