//Dijkstra - single source shortest path
//CSES 1671
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PB push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;


const int inf = 2000000000;
const ll infLL = 900000000000000000;

#define optimize( ) ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e5 + 123;
ll dist[ mx];
vii adj[mx];
ll par[mx];

void dijkstra( int s, int n)
{
    for(int i = 0; i <= n; i++)
        dist[ i] = infLL;
    priority_queue<pll, vll, greater<pll>> pq;
    pq.push({0, s});
    dist[s]= 0;

    while(!pq.empty( ))
    {
        int u = pq.top( ).second;
        ll curD = pq.top( ).first;
        pq.pop( );

        if(dist[u] < curD)
            continue;

        for(auto p: adj[ u])
        {
            int v = p.first;
            ll w = p.second;
            if(curD+w < dist[ v])
            {
                dist[ v] = curD + w;
                par[v] = u;
                pq.push({ dist[ v], v});
            }
        }
    }
}

int main( )
{
    optimize( );

    int n, m, i, u, v;
    ll w;
    cin >> n >> m;
    for(i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[ u].PB({ v, w});
        adj[ v].PB({ u, w});
    }
    dijkstra( 1, n);
    for(i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << endl;
    return 0;
}
