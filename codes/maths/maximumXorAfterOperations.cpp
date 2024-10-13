// @leet start
// leet code 2317 problem
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int xorVal = 0;
        for(int i = 31; i>=0; i--){
            long long bitCounts = 0;
            for(int  j = 0;j< n;j++){
                bitCounts += nums[j]&(1<<i);
            }
            if(bitCounts == 0 || bitCounts&1){
                int bit = 1;
                if(bitCounts == 0){
                    bit = 0;
                }
                ans = ans|(bit<<i);
            }
            else{
                ans = ans|(1<<i);
            }
        }

        return ans;
    }

};
// @leet end
