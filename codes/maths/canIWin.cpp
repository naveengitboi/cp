// @leet start
// can i win leetcode 464
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
class Solution {
public:
    int dp[1<<20];
    bool dfs(int m, int d, int mask){
        if(d<=0) return 0;
        if(dp[mask] != -1) return dp[mask];
        for(int i = 0; i< m; i++){
            if(!(mask&(1<<i)) and !dfs(m, d-(i+1), mask|(1<<i) ) ){
                return dp[mask] = 1;
            }
        }
        return dp[mask] = 0;
    }
    bool canIWin(int m, int d) {
        if(d == 0) return 1;
        int total = m*(m+1)/2;
        if(total< d) return 0;
        if(total == d) return m%2;
        memset(dp, -1, sizeof dp );
        return dfs(m, d, 0);
    }
};
// @leet end
