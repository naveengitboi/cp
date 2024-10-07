#include <bits/stdc++.h>
using namespace std;

//2696 leetcode
//
//

//my appraoch to this problem
int minLength(string s){
    while(true){
        int i = 0;
        int n = s.length();
        string newS = "";
        bool seen = false;
        while(i < n -1){
            string temp ="";
            temp += s[i];
            temp += s[i+1];
            if(temp == "AB" || temp == "CD"){
                i+=2;
                seen = true;
            }
            else{
                newS += s[i];
            }
        }
        if(i == n-1){
            newS += s[i];
        }
        s = newS;
        if(!seen){
            break;
        }
    }
    return s.length();
}


//using stacks easy problem
//

int minLengthUsingStacks(string s){
    stack<char> st;
    for(int  i = 0; i< s.length(); i++){
        if(!st.empty() && (st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D')){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    return st.size();
}
