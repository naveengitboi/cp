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


//four sum problem 2
//

int countZeroTuples(vi& a, vi& b , vi& c, vi& d){
    int count = 0;
    int n = a.size();
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    sort(begin(c), end(c));
    sort(begin(d), end(d));

    for(int i = 0; i< n; i++){
        if(i > 0 && a[i] == a[i-1]){
            continue;
        }
        for(int j = 0; j< n ; j++){
            if(j > 0 && b[j] == b[j-1]){
                continue;
            }
            for(int k = 0; k < n; k++){

                if(k > 0 && c[k] == c[k-1]){
                    continue;
                }
                for(int l = 0; l < n; l++){

                    if(l > 0 && d[l] == d[l-1]){
                        continue;
                    }
                    int sum = a[i];
                    sum+= b[j];
                    sum+= c[k];
                    sum+= d[l];
                    if(sum == 0){
                        count++;
                    }
                    
                }
            }
        }
    }

    return count;
}
