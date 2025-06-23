///https://lightoj.com/problem/drunk

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mx = 2e4 + 123;
vector< int> adj[ mx];
int vis[ mx], pathVis[ mx];
map< string, int> mp;


bool dfs( int u)
{
    vis[ u] = 1;
    pathVis[ u] = 1;

    for(auto v: adj[ u])
    {
        if( vis[ v] == 0)
        {
            if( dfs( v) == true)
                return true;
        }
        else if( pathVis[ v] == 1)
        {
            return true;
        }
    }
    pathVis[ u] = 0;
    return false;
}


int main( )
{
    ll t, n, i, j, u, v, m;
    cin >> t;
    string s1, s2;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for(i = 1; i <= 2*n; i++)
        {
            vis[ i] = 0;
            pathVis[ i] = 0;
            adj[ i].clear( );
        }
        mp.clear( );

        j = 1;
        while(n--)
        {
            cin >> s1 >> s2;
            if(mp[s1] == 0)
            {
                mp[s1] = j;
                j++;
            }
            if(mp[s2] == 0)
            {
                mp[s2] = j;
                j++;
            }
            u = mp[ s1];
            v = mp[ s2];
            adj[ u].push_back( v);
        }
        n = j-1;

        string s = "Yes";
        for(i = 1; i <= n; i++)
        {
            if( vis[ i] == 0)
            {
                if(dfs( i) == true)
                {
                    s = "No";
                }
            }
        }
        cout << "Case " << tc << ": " << s << endl;
    }
    return 0;
}
