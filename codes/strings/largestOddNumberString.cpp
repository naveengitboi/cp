#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string s){
    string ans = "";
    string prev = "";
    for(int i = 0; i< s.length(); i++){
        char c = s[i];
        if((c-'0')%2 == 0){
            prev += c;
        }else{
            ans += prev + c;
            prev = "";
        }
    }

    return ans;
}
