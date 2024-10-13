// @leet start
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string ans="";
        int q = num/den;
        int rem = num%den;
        ans += to_string(q);
        if(!rem){
            return ans;
        }
        else{
            ans.push_back('.');
            unordered_map<int, int>mpp;
            while(rem != 0){
                if(mpp.find(rem) != mpp.end()){
                    int len = mpp[rem];
                    string beforeLen = ans.substr(0, len);
                    string afterLen = ans.substr(len-1);
                    ans = beforeLen+'(' + afterLen + ')';
                    break;
                }else{
                    rem *=10;
                    q = rem/den;
                    rem = rem%den;
                    mpp[rem] = ans.length();
                    ans += to_string(q);
                }

            }
        }
        return ans;
    }
};
// @leet end
