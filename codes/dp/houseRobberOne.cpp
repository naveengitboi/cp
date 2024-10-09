// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int solve(int i,int n, vector<int>& nums){
        if(i == n-1){
            return nums[i];
        }
        if(i == n-2){
            return max(nums[i], nums[i+1]);
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int rob = nums[i] + solve(i+2, n, nums);
        int dontRob = solve(i+1, n, nums);
        return dp[i] = max(rob, dontRob);

    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return solve(0, nums.size(), nums);
    }
};
// @leet end
