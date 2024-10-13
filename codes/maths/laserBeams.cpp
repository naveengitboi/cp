// @leet start
// leetcode 2125
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        map<int, int> mpp;
        int m = bank.size();
        if(m == 0) return 0;
        int n = bank[0].size();
        for(int i =0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(bank[i][j] == '1'){
                    mpp[i]++;
                }
            }
        }
        int i = 0;
        int ans = 0;
        while(i< m){
            int initial = mpp[i];
            if(initial!= 0){
                i++;
                while(i < m && mpp[i] == 0){
                    i++;
                }
                ans += mpp[i]*initial;
            }else{
                i++;
            }
        }
        return ans;
    }
};
// @leet end
