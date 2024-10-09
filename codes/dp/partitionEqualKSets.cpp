
// @leet start
// leet code 698 problem
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
private:
    int getSum(vector<int>& nums){
        int sum = 0;
        for(auto num: nums){
            sum += num;
        }
        return sum;
    }

public:
    int target;
    vector<bool> visited;
    bool solve(int i, int k, vector<int>& nums, int subsum, vector<bool>& visited){
        if(k == 0){
            return true;
        }
        if(subsum == target){
            return solve(0, k-1, nums, 0, visited);
        }
        for(int j = i; j< nums.size(); j++){
            if(visited[j] || subsum + nums[j] > target){
                continue;
            }
            visited[j] = true;
            int ans = solve(j+1, k-1, nums, subsum+nums[j], visited);
            if(ans) return true;
            visited[j] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = getSum(nums);
        int n = nums.size();
        visited.resize(n, false);
        if(total%k != 0) return false;
        target = total/k;
        return solve(0, k, nums, 0, visited);
    }
};
// @leet end
