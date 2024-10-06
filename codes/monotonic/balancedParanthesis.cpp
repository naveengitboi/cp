#include <bits/stdc++.h>
using namespace std;


bool balancedParenthesis(string s){
    stack<char> st;
    for(int i = 0; i< s.length(); i++){
        char c = s[i];
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else{
            if(c == ')'){
                if(st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            }
            else if(c == '}'){
                if(st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                if(st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
    }

    return true;
}
