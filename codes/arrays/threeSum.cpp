#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>


vvi threeSumOptimal(vi& nums){
    sort(nums.begin() , nums.end());

    vvi ans;
    int n = nums.size();
    for(int i = 0; i< n; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j < k){
            int target = - nums[i];
            int sum = nums[j] + nums[i];
            if(sum == k){
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j+1< n && nums[j] == nums[j+1]) j++;
                j++;
                while(k > 0 && nums[k] == nums[k-1]) k--;
                k--;
            }
            else if(sum < target){
                k--;
            }else{
                j++;
            }
        }
    }

    return ans;
}



int threeSumClosest(vi& nums, int target){
    int n = nums.size();
    int maxDiff = INT_MAX;
    int ans = 0;
    sort(begin(nums), end(nums));
    for(int i = 0;i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        int l = target - nums[i];
        while(j < k){
           int sum = nums[j] + nums[k];
            if(abs(l - sum) < maxDiff){
                ans = (sum + nums[i]);
                maxDiff = abs(l-sum);
            }
            if(sum > l) k--;
            else j++;
        }
    }
    return ans;
}












