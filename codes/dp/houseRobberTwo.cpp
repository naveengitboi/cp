// @leet start
#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int solve(int i,int k,  vector<int>& nums, vector<int>& dp){
        if(i < k){
            return 0;
        }
        if(i == k){
            return nums[i];
        }
        if(i == k+1){
            return max(nums[i], nums[i-1]);
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int rob = nums[i] + solve(i-2, k, nums, dp);
        int dontRob =  solve(i-1, k, nums, dp);
        return dp[i] = max(rob, dontRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> dp1(n, -1);
        int ans1 = solve(n-1, 1, nums, dp1); 
        vector<int> dp2(n, -1);
        int ans2 = solve(n-2, 0, nums, dp2);
        return max(ans1, ans2);
    }
};
// @leet end
