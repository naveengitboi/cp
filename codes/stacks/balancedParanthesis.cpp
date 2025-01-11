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


class Solution {
public:
    int balancedParanthesisi(string s) {
        stack<int> st;
        for(char c: s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                char x = st.top();
                st.pop();
                if(st.empty()) return false;
                if((x == ')' && c == '(' ) || (x == '}' && c == '{')  || ( x == ']' && c == '[')) continue;
                else return false;
            }
        }
        if(st.emtpy()) return 1;
        return 0;
    }
};

