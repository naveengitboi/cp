#include <bits/stdc++.h>
#include <climits>
using namespace std;

int maxSubProd(vector<int> &nums) {
    int ans = INT_MIN;
    int minProd = 1, maxProd = 1;

    for(int i = 0; i< nums.size(); i++){
        if(nums[i] < 0){
            swap(maxProd, minProd);
        }
        maxProd = max(maxProd*nums[i], nums[i]);
        minProd = min(minProd*nums[i], nums[i]);
        
        ans = max(ans, maxProd);
    }

    return ans;
}


int subarrayProdBelowK(vector<int>& nums,int k){
    int ans = 0;
    //given nums[i] >= 0;
    for(int i = 0; i< nums.size(); i++){
        long long prod  = 1;
        for(int j = i; j< nums.size(); j++){
           prod = prod*nums[j];
            if(prod < k){
                ans++;
            }else{
                break;
            }
        }
    }
    return ans;
}
