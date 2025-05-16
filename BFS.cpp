#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mx = 2e5 + 5;
vector< int> adj[ mx];
int lev[ mx], ans[ mx];
int cnt;

void bfs( int s)
{
      lev[ s] = 1;
      queue<int> q;
      q.push( s);
      cnt++;

      while( !q.empty( ))
      {
            int u = q.front( );
            q.pop( );

            for(auto v: adj[ u])
            {
                  if(lev[ v] == 0)
                  {
                        lev[ v] = lev[ u] + 1;
                        if(lev[ v] > cnt)
                              cnt = lev[ v];
                        q.push( v);
                  }
            }
      }
}

int main( )
{
      int t, n, i, j, x, mx;
      cin >> t;
      while(t--)
      {
            cin >> n;
            for(i = 1; i <= n; i++)
            {
                  adj[ i].clear( );
                  lev[ i] = 0;
                  ans[i] = 0;
            }
            for(i = 1; i <= n; i++)
            {
                  cin >> x;
                  adj[ i].push_back( x);
            }

            priority_queue <int, vector<int>, greater<int>>  pq;
            for(i = 1; i <= n; i++)
            {
                  if(lev[ i] == 0)
                  {
                        cnt = 0;
                        bfs( i);
                        pq.push(cnt);
                  }
            }
            int ans = 0, a1;
            while(pq.size() > 1)
            {
                a1 = 0;
                a1 = pq.top( );
                pq.pop( );
                a1 += pq.top( );
                pq.pop( );
                ans += a1;
                pq.push(a1);
            }
            cout << ans << endl;
      }
      return 0;
}

