#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>
#define sip stack<pair<int, int>>

class Solution {
public:
    vi ans;
    void push(sip& st){
        pii top = sip.top();
        if(top.second < 0) sip.push({0, top.second});
        else{
            sip.push({0, 0});
        }
    }
    void pop(sip& st){
        if(sip.empty()) return ;
        sip.pop();
    }
    int getMin(sip& st){
        if(sip.empty()) return 0;
        return sip.top().second;
    }
    vi implementMinStack(vs calls){
        sip st;
        for(auto call: calls){
            if(call == "push") push(sip);
            else if(call == "pop") pop(sip);
            else ans.push_back(getMin(sip));
        }
    }
    
};

