//codeforces 1093D

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

const int mx = 3e5 + 5;
vector< int> adj[ mx];
int ara[mx], kp[ mx];
int c1 = 0, c2 = 0;
bool pos, vis[ mx];

void func( )
{
    int i, j = 1;
    for(i = 0; i < mx; i++)
    {
        ara[i] = j;
        j *= 2;
        j %= mod;
    }
}

void  dfs( int u, int col)
{
    vis[u] = 1;
    kp[ u] = col;
    if(col == 0)
        c1++;
    else
        c2++;

    for(auto v: adj[ u])
    {
        if( vis[ v] == 0)
        {
            dfs( v, 1-col);
        }
        else if(kp[u] == kp[ v])
        {
            pos = 0;
        }
    }
}

int main( )
{
    func( );
    int t, n, i, j, m, mx, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 1; i <= n; i++)
        {
            adj[ i].clear( );
            kp[i] = -1;
            vis[ i] = 0;
        }
        for(i = 1; i <= m; i++)
        {
            cin >> u >> v;
            adj[ u].push_back( v);
            adj[ v].push_back( u);
        }
        ll ans = 1;
        for(i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                pos = 1, c1 = 0, c2 = 0;
                dfs(i, 0);
                if(pos == 0)
                {
                    ans = 0;
                    break;
                }
                else
                {
                    ans *= ara[c1] + ara[c2];
                    ans %= mod;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
