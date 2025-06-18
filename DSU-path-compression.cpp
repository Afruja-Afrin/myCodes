///https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    vector< int> par;

    int find_Par( int u){
        if(u == par[ u])
            return u;
        return par[ u] = find_Par( par[ u]);
    }

    void Union( int u, int v){
        par[ v] = u;
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size( );

        for(int i = 0; i < n; i++)
            par.push_back( i);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if( adj[ i][ j]){
                    int u = find_Par( i);
                    int v = find_Par( j);

                    if( u != v){
                        Union( u, v);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(par[ i] == i)
                ans++;
        }
        return ans;
    }
};
