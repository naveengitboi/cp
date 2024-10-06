#include <bits/stdc++.h>
using namespace std;


string removeOuterMostParentheses(string s){
    string ans;
    int count = 0;
    int n = s.length();
    for(int i = 0;i<n; i++){
        if(s[i] == '(' && count == 0){
            count++;
        }
        else if(count == 1 && s[i] == ')'){
            count--;
        }
        else{
            if(s[i] == '('){
                count++;
            }else{
                count--;
            }
            ans += s[i];
        }
    }
    return ans;
}
