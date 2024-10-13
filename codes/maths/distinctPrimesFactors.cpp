// @leet start
// distinctPrimeFactors 2521 lc
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:

    vector<int> getPrimesFacs(int num){
        vector<int> primes;
        for(int i = 2; i*i<= num;i++){
            while(num%i == 0){
                num/=i;
                primes.emplace_back(i);
            }
        }
        if(num > 1) primes.emplace_back(num);
        return primes;

    }
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for(int i =0; i< nums.size(); i++){
             vector<int> pf = getPrimesFacs(nums[i]);
            for(auto q : pf) s.insert(q);
        }
        return s.size();
    }
};
// @leet end
