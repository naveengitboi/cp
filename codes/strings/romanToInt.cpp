#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int romanToInt(string s){
    unordered_map<char, int>mpp;
    mpp.insert({'I', 1});
    mpp.insert({'V', 5});
    mpp.insert({'X', 10});
    mpp.insert({'L', 50});
    mpp.insert({'C', 100});
    mpp.insert({'D', 500});
    mpp.insert({'M', 1000});
    int ans=0;
    int prev;
    for(int i = s.length()-1; i>=0; i--){
        int curr = mpp[s[i]];
        if(i == s.length() - 1){
            prev = mpp[s[i]];
            ans += prev;
            continue;
        }
        if(curr < prev){
            ans -= curr;
        }else{
            ans += prev;
        }
        prev = curr;
    }
    return ans;
}
