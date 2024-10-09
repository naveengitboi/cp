// @leet start
// leet code 396 problem
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int prev = 0;
        for(int i =0; i< n;i++){
            int num = nums[i];
            prev += (i*num);
            sum += num;
        }
        int maxi = INT_MIN;
        for(int i = 0; i< n; i++){
            int curr = prev - (n-1)*(nums[n-i-1]) + (sum - nums[n-i-1]);
            maxi = max(maxi, curr);
            prev = curr;
        }
        return maxi;

    }
};
// @leet end
