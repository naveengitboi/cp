//leetcode 97


// @leet start
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
