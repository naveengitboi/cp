#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>


class Solution {
public:
    vvi directions = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n ==0  || grid[0][0] == 1) return -1;
        auto isValid = [&](int x, int y){
            return x >= 0 && x < m && y>= 0 && y<n;
        };
        queue<pii> q;
        q.push({0,0});
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pii curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                
                if(x == m-1 && y == n-1){
                    return level+1;

                }

                for(auto& dir: directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isValid(x_, y_) && grid[x_][y_] == 0){
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }

            level++;
        }
        return -1;
        
    }
};

