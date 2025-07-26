#include<bits/stdc++.h>
using namespace std;
#define ll long long
char ch[ 1002][ 1002];
string s;
int lev[ 1002][ 1002], n, m;
int dx[ ] = { 0, 0, -1, +1};
int dy[ ] = { -1, +1, 0, 0};
char mp[1002][1002];
pair<int,int> par[1002][1002];


void bfs( int x, int y)
{
    int i, j, x1, y1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            lev[i][j] = 1e7;
            mp[i][j] = '*';
        }
    }

    lev[ x][ y] = 1;
    queue< pair< int, int>> q;
    q.push({ x, y});
    mp[ x][ y] = 'A';

    while(!q.empty( ))
    {
        x = q.front( ).first;
        y = q.front( ).second;
        q.pop( );

        for( i = 0; i < 4; i++)
        {
            x1 = x + dx[ i];
            y1 = y + dy[ i];

            if(x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && ch[ x1][ y1] != '#' && lev[ x][ y]+1 < lev[ x1][ y1])
            {
                lev[ x1][ y1] = lev[ x][ y]+1;
                par[x1][y1] = {x, y};
                q.push({ x1, y1});
                if(x1 == x+1)
                {
                    mp[ x1][ y1] = 'D';
                }
                else if(x1 == x-1)
                {
                    mp[ x1][ y1] = 'U';
                }
                else if(y1 == y+1)
                {
                    mp[ x1][ y1] = 'R';
                }
                else if(y1 == y-1)
                {
                    mp[ x1][ y1] = 'L';
                }
            }
        }
    }
}

int main( )
{
    int t, i, j;
    cin >> n >> m;
    for( i = 1; i <= n; i++)
    {
        for( j = 1; j <= m; j++)
            cin >> ch[ i][ j];
    }
    int a, b;
    for( i = 1; i <= n; i++)
    {
        for( j = 1; j <= m; j++)
        {
            if(ch[ i][ j] == 'A')
            {
                bfs( i, j);
            }
            if(ch[ i][ j] == 'B')
                a = i, b = j;
        }
    }
    if(mp[ a][ b] == '*')
    {
        cout << "NO\n";
    }
    else
    {
        while(mp[ a][ b] != 'A')
        {
            s.push_back(mp[ a][ b]);
            i = par[ a][ b].first;
            j = par[ a][ b].second;
            a = i;
            b = j;
        }
        cout << "YES\n";
        cout << s.size( ) << endl;
        reverse( s.begin( ), s.end( ));
        cout << s << endl;
    }
    return 0;
}

