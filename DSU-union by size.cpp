#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector< int> par;
vector< int> sz;

int find_Par( int u)
{
    if(u == par[ u])
        return u;

    return par[ u] = find_Par( par[ u]);
}


void Union( int u, int v)
{
    if( sz[ u] < sz[ v])
    {
        swap( u, v);
    }
    par[ v] = u;
    sz[ u] += sz[ v];
}

int main( )
{
    int t, n, i, j, m, u, v;
    cin >> n >> m;

    for(i = 0; i <= n; i++)
        par.push_back( i);
    sz.resize( n, 1);

    while(m--)
    {
        cin >> u >> v;

        int uR = find_Par( u);
        int vR = find_Par( v);

        if( uR != vR)
        {
            Union( uR, vR);
        }
    }
    return 0;
}
/// time complexity O( n * alpha( n))
