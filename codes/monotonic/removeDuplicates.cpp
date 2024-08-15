#include <bits/stdc++.h>
#include <string>
#include <sys/types.h>
#include <unordered_map>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define vs vector<string> 

//wrong approach
string removeDuplicates(string s){
  stack<char> st;
  string ans;
  unordered_map<char, int> mp;
  for(char &c: s){
    mp[c]++;
  }
  for(auto c : s){
      int diff = c - 'a';
    while(!st.empty() && st.top() > diff && mp[c] > 1){
      st.pop();
      mp[c]--;
    }
    st.push(c);
  }

  for(auto &c: mp){
    ans+= c.first;
  }
  
  return ans;
}
