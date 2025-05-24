#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mx = 1e5 + 5;
vector< int> adj[ mx];
int vis[ mx], pos;
int x;
map<int, int> par;
vector<ll> vv;

void DFS( int u)
{
    vis[u] = 1;

    for(auto v: adj[u])
    {
        if(vis[v] == -1 && pos == 0)
        {
            DFS( v);
            par[v] = u;
            vis[v]= 0;
        }
        else if(vis[v] == 0)
        {
            pos = 1;
            par[u] = v;
            x = v;
            if(vv.size( ) == 0)
            {
                int y = x;
                while(par[x] != y)
                {
                    vv.push_back(par[x]);
                    x = par[x];
                }
                vv.push_back(par[x]);
                vv.push_back(vv[0]);
            }
            return;
        }
    }
}

int main( )
{
    int t, n, i, j, m;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        vis[i] = -1;
    for(i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i = 1; i <= n; i++)
    {
        if(vis[i] == -1)
        {
            pos = 0, vis[i] = 0;
            DFS(i);
            if(pos == 1)
            {
                cout << vv.size( ) << endl;
                for(auto u: vv)
                    cout << u << " ";
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
