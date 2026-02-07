//https://cses.fi/problemset/task/1651

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 2e5+123;
ll arr[ mx], tree[ mx*4] = { 0}, lz[ mx*4] = { 0};

void build( ll ind, ll low, ll high)
{
    if( low == high)
    {
        tree[ ind] = arr[ high];
        return;
    }
    ll mid = (low + high) / 2;
    build( 2*ind, low, mid);
    build( 2*ind+1, mid+1, high);
}

void updateLazy( ll ind, ll low, ll high, ll l, ll r, ll val)
{
    if(low >= l && high <= r)
    {
        lz[ ind] += val;
        return;
    }
    if( r < low || l > high)
        return;
    ll mid = ( low + high) / 2;
    updateLazy( 2*ind, low, mid, l, r, val);
    updateLazy( 2*ind+1, mid+1, high, l, r, val);
}

ll query( ll root, ll low, ll high, ll ind)
{
    if( low == high)
    {
        return arr[ ind] + lz[ root];
    }
    if( ind < low || ind > high)
        return 0;
    ll mid = ( low + high) / 2;
    if( ind <= mid)
        return lz[ root] + query( 2*root, low, mid, ind);
    else
        return lz[ root] + query( 2*root+1, mid+1, high, ind);
}

int main( )
{
    ll n, q, i, l, r, val, ind, tp;
    cin >> n >> q;

    for( i = 1; i <= n; i++)
    {
        cin >> arr[ i];
    }
    build( 1, 1, n);
    while( q--)
    {
        cin >> tp;
        if( tp == 2)
        {
            cin >> ind;
            cout << query(1, 1, n, ind) << endl;
        }
        else
        {
            cin >> l >> r >> val;
            updateLazy( 1, 1, n, l, r, val);
        }
    }
    return 0;
}
