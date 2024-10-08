#include <bits/stdc++.h>
using namespace std;


//method 1
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            for(int j = 0; j<n ; j++){
                if(i ==j){
                    continue;
                }
                if(nums[i] + nums[j] == target){
                    ans++;
                }
            }
        }
        return ans;
    }

    ///using hashmaps and permuations and combinations
    int methodTwo(vector<string>& nums, string target) {
        unordered_map<string, int>freq;
        for(int i = 0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int ans = 0;
        for(int i = 1; i< target.length(); i++){
            string leftPart = target.substr(0,i);
            string rightPart = target.substr(i, target.length());
            if(leftPart != rightPart){
                ans += (freq[leftPart]*freq[rightPart]);
            }else{
                ans += (freq[leftPart]*(freq[rightPart] - 1));
            }
        }

        return ans;

    }
};



