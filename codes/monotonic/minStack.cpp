#include <bits/stdc++.h>
using namespace std;


class Minstack{
public:
    stack<pair<int, int>> st;
    int mini;
    void push(int x){
        if(st.empty() || st.top().second > x){
            st.push({x, x});
        }
        if(st.top().second < x){
            st.push({x, st.top().second});
        }
        mini = st.top().second;
    }
    void pop(){
        if(!st.empty()){
            st.pop();
        }
        if(!st.empty()){
            mini = st.top().second;
        }
    }
    int top(){
        if(!st.empty()){
            return st.top().first;
        }
        return -1;
    }
    int getMin(){
        return mini;
    }
};

