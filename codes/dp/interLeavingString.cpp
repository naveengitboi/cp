//leetcode 97


// @leet start
// method one recursive + memoization
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int m, n, l;
    bool solve(int i, int j,int k, string& s1, string& s2, string& s3){
        if(k == l){
            return true;
        }
        bool ans = false;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i < m && s1[i] == s3[k]){
            ans = ans || solve(i+1, j, k+1, s1,s2,s3);
        }
        if(j < n && s2[j] == s3[k]){
            ans = ans || solve(i, j+1, k+1, s1, s2, s3);
        }

        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        l = s3.length();
        dp.resize(m+1, vector<int>(n+1, -1));
        if(m+n != l) return false;
        return solve(0,0,0,s1,s2,s3);

    }
};
// @leet end
//
//
// method two iterative 2d dp
class Solve {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int l = s3.length();
        if(m + n != l) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i<=m;i++){
            if(s1[i-1] == s3[i-1] && dp[i-1][0]){
                dp[i][0] = true;
            }
        }
        for(int j = 1; j<=n ;j++){
            if(s2[j-1] == s3[j-1] && dp[0][j-1]){
                dp[0][j] = true;
            }
        }
        for(int i = 1; i<=m ; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1] == s3[i+j-1] && dp[i-1][j] || s2[j-1] == s3[i+j-1] && dp[i][j-1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[m][n];

    }
};
// @leet end
