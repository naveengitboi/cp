//leet code 2453
// @leet start
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int> mpp; 
        int maxFreq = 0;
        for(auto num: nums){
            int r = num%space;
            mpp[r]++;
            maxFreq = max(maxFreq, mpp[r]);
        }
        int ans = INT_MAX;
        for(auto num: nums){
            int r = num%space;
            if(maxFreq == mpp[r]){
                ans = min(num, ans);
            }
        }
        return ans;
    }
};
// @leet end
