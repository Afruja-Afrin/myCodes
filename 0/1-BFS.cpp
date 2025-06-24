///https://www.spoj.com/problems/KATHTHI/en/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define infLL 1000000000
const int mx = 1005;
char ch[ mx][ mx];
int lev[ mx][ mx];
int dx[ ] = { 1, -1, 0, 0};
int dy[ ] = { 0, 0, -1, 1};


void bfs( int x, int y, int n, int m)
{
    deque< pair< int, int>> pq;
    pq.push_front({ x, y});
    lev[ x][ y] = 0;

    while( !pq.empty( ))
    {
        int u = pq.front( ).first;
        int v = pq.front( ).second;
        pq.pop_front( );

        for(int i = 0; i < 4; i++)
        {
            int x1 = u + dx[ i];
            int y1 = v + dy[ i];

            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m)
            {
                if(ch[ u][ v] != ch[ x1][ y1] && lev[ x1][ y1] > lev[ u][ v] + 1)
                {
                    lev[ x1][ y1] = lev[ u][ v] + 1;
                    pq.push_back( { x1, y1});
                }
                else if(ch[ u][ v] == ch[ x1][ y1] && lev[ x1][ y1] > lev[ u][ v])
                {
                    lev[ x1][ y1] = lev[ u][ v];
                    pq.push_front( { x1, y1});
                }
            }
        }
    }
}

int main( )
{
    int t, n, i, j, k, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
        {
            scanf("%s", ch[i]);
            for(j = 0; j < m; j++)
                lev[i][j] = infLL;
        }
        bfs( 0, 0, n, m);
        printf("%d\n", lev[ n-1][ m-1]);
    }
    return 0;
}

