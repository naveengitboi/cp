#include <bits/stdc++.h>
using namespace std;


class Minstack{
public:
    stack<pair<int, int>> st;
    void push(int x){
        if(st.empty() || st.top().second > x){
            st.push({x, x});
        }
        if(st.top().second < x){
            st.push({x, st.top().second});
        }
    }
    void pop(){
        if(!st.empty()){
            st.pop();
        }
    }
    int top(){
        if(!st.empty()){
            return st.top().first;
        }
        return -1;
    }
    int getMin(){
        if(!st.empty()){
            return st.top().second;
        }
        return -1;
    }
};

