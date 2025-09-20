// https://cses.fi/problemset/task/1679/
// works for directed acyclic graph

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 1e5 + 123;
vector< int> adj[ mx];
bool vis[ mx], pathVis[ mx];
map< string, int> mp;
stack< int> st;

bool cycd( int u)
{
    vis[ u] = 1;
    pathVis[ u] = 1;

    for(auto v: adj[ u])
    {
        if( vis[ v] == 0)
        {
            if( cycd( v) == true)
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


void dfs( int u)
{
    vis[ u] = 1;

    for(auto v: adj[ u])
    {
        if( vis[ v] == 0)
        {
            dfs( v);
        }
    }
    st.push( u);
    return;
}


int main( )
{
    ll n, i, j, m;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[ u].push_back( v);
    }

    bool pos = 1;
    for(i = 1; i <= n; i++)
    {
        if( vis[ i] == 0)
        {
            if(cycd( i) == true)
            {
                pos = 0;
                break;
            }
        }
    }
    if( pos == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(i = 1; i <= n+5; i++)
    {
        vis[ i] = 0;
    }


    for(i = 1; i <= n; i++)
    {
        if( vis[ i] == 0)
        {
            dfs( i);
        }
    }

    while( st.size( ) > 0)
    {
        cout << st.top( ) << " ";
        st.pop( );
    }
    cout << endl;

    return 0;
}
