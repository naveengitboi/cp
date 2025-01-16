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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] == 1) return -1;

        typedef pair<int, pair<int, int>>P;
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, {0,0}});
        vvi result(m, vi(n, INT_MAX));
        result[0][0] = 0;

        while(!pq.empty()){
            P top = pq.top();
            pq.pop();
            int dist = top.first;
            int x = top.second.first;
            int y = top.second.second;

            for(auto& dir: directions){
                int x_ = x+dir[0];
                int y_ = y+dir[1];
                int wt = 1;
                if(isValid(x_,y_) && grid[x_][y_] == 0 && result[x_][y_]>dist+wt){
                    result[x_][y_] = dist+wt;
                    grid[x_][y_] = 1;
                    pq.push({dist+wt, {x_, y_}});
                }
            }

        }

        if(result[m-1][n-1] == INT_MAX) return -1;
        return result[m-1][n-1];
        
    }
};

