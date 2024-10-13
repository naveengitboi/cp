//166. Fraction to Recurring Decimal
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string ans="";
        int sign = 1;
        if(den < 0 || num < 0) sign = -1;
        if(den < 0 && num < 0) sign = 1;
        num = abs(num);
        den = abs(den);
        long long q = num/den;
        long long rem = num%den;
        ans += to_string(q);
        if(!rem){
            //pass 
        }
        else{
            ans.push_back('.');
            unordered_map<long long, long long>mpp;
            while(rem != 0){
                if(mpp.find(rem) != mpp.end()){
                    long long len = mpp[rem];
                    cout<<rem<<" " <<ans<<endl;
                    string beforeLen = ans.substr(0, len);
                    string afterLen = ans.substr(len);
                    ans = beforeLen+'(' + afterLen + ')';
                    break;
                }else{
                    mpp[rem] = ans.length();
                    rem *=10;
                    q = rem/den;
                    rem = rem%den;
                    ans += to_string(q);
                }

            }
        }
        cout<<sign<<endl;
        if(ans == "0") return "0";
        if(sign == 1){
            return ans;
        }else{
            ans = "-"+ans;
        }
        return ans;

    }
};
// @leet end
