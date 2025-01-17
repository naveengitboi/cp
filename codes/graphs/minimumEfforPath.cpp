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
    vvi directions = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auot isValid = [&](int x, int y){
            return x>=0 && x<m && y>=0 && y<n;
        };
        vvi result(m , vi(n , INT_MAX));
        result[0][0] = 0;
        typedef pair<int, pair<int, int>>P;
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            int node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(auto& dir: directions){
                int x_ = x+dir[0];
                int y_ = y + dir[1];
                if(isValid(x_, y_)){
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    absDiff = max(absDiff, diff);
                    if(result[x_][y_] > absDiff){
                        result[x_][y_] = absDiff;
                        pq.push({absDiff, {x_, y_}});
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
};

