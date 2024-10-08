// @leet start
// leet code 2364
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //will try to get good pairs and total pairs are easy to get
        long long n = nums.size();
        long long totalPairs = (n)*(n-1)/2;
        long long goodpairs = 0;
        unordered_map<int, int> mpp;
        for(int i = 0; i< n; i++){
            int r = nums[i] - i;
            if(mpp.find(r) != mpp.end()){
                goodpairs+= mpp[r];
            }
            mpp[r]++;
        }
        return totalPairs - goodpairs;
    }
};
// @leet end
