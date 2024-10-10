// @leet start
// leetcode 962
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int diff = 0;
        int n = nums.size();
        int maxi = nums[n-1];
        vector<int> maxiOccured(n);
        for(int i = n-1; i>=0; i--){
            maxiOccured[i] = max(maxiOccured[i], maxi);
        }
        for(int i = n-1; i>=0 ; i--){
            if(nums[i] > maxiOccured[i]){
                continue;
            }
            for(int j = i+1; j<n; j++){
                if(nums[j] > nums[i]) continue;
                diff = max(diff, j - i);
            }
        }
        return diff;
    }
};
// @leet end



// @leet start
// leet code 962
#include <bits/stdc++.h>
using namespace std;
class Solve {
public:
    int maxWidthRamp(vector<int>& nums) {
        int diff = 0;
        int n = nums.size();
        int maxi = nums[n-1];
        vector<int> maxiOccured(n);
        for(int i = n-1; i>=0; i--){
            maxiOccured[i] = max(nums[i], maxi);
            maxi = maxiOccured[i];
        }
        int l = 0;
        for(int r= 0; r < n; r++){
            while(nums[l] >maxiOccured[r]){
                l++;
            }
            diff = max(diff, r-l);
        }
        return diff;
    }
};
// @leet end
