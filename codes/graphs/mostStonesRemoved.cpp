#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>

class Solution {
public:
    int rowSize, colSize;
    vvi directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void doDfs(vvi& grid, vvb& visited, int x, int y){
        visited[x][y] = true;
        auto isValidMove = [&](int x, int y){
            return x>= 0 && x< rowSize && y >= 0 && y< colSize;
        };
        if(grid[x][y]){
            for(auto& dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isValidMove(x_,y_) && visited[x_][y_] == false){
                    doDfs(grid, visited, x_, y_);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones){
        int n = stones.size();
        sort(stones.begin(), stones.end());
        rowSize = stones[n-1][0];
        colSize = stones[n-1][1];
        vvi grid(rowSize, vi(colSize, 0));

        for(auto& loc: stones){
            int x = loc[0];
            int y = loc[1];
            grid[x][y] = 1;
        }
        vvb visited(rowSize, vector<bool>(colSize, false));
        int groups = 0;
        for(auto& loc: stones){
            int x = loc[0];
            int y = loc[1];
            if(visited[x][y]==false){
                doDfs(grid, visited, x, y);
            }
            groups++;
        }
        return (n - groups);

    }
};

