#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int> 


vvi fourSum(vi& nums, int target){
    vvi ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i< n; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }
            int k = j+1;
            int l = n-1;
            while(k < l){
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while(k < n-1 && nums[k] == nums[k+1]){
                        k++;
                    }
                    k++;
                    while(l >= 0 && nums[l] == nums[l-1]){
                        l--;
                    }
                    l--;
                }
                else if(sum > target){
                    l--;
                }else{
                    k++;
                }
            }

        }
    }

    return ans;
}

