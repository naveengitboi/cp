// @leet start
// leet code 3128 problem
#include <bits/stdc++.h>
#include <unordered_map>
using namespace  std;
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        unordered_map<int, int>rows;
        unordered_map<int, int>cols;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j]){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j]){
                    ans += (rows[i] - 1)*(cols[j]-1);
                }
            }
        }
        return ans;
    }
};
// @leet end
