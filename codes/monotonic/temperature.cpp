
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


vi dailyTemp(vi& temp){
  stack<pair<int, int>> st;

  unordered_map<int, int> dp; 

  vi result;
  int k = 0;

  for(int i = temp.size() -1; i>= 0; i--){
    int t = temp[i];
    bool found = false;
    stack<pair<int, int>> copy = st;
    if(dp.find(t) != dp.end()){
        result.push_back(dp[t]);
    }
    else{
    while(!copy.empty()){
      if(t < copy.top().first){
        result.push_back(k - copy.top().second);
        dp[t] = k - copy.top().second;
        found = true;
        break;
      }
      else{
        copy.pop();
      }
    }
    }
    if(!found){
        result.push_back(0);
    }
    st.push({temp[i], k});
    k++;
  }
  reverse(result.begin(), result.end());
  return result ;
}

vi correctAns(vi& temp){
  
  stack<int> st;
  int n = temp.size();

  vi result(n, 0);
  for(int i =0; i< n; i++){
    while(!st.empty() && temp[st.top()] < temp[i]){
      int j = st.top();
      st.pop();
      result[j] = i - j;
    }

    st.push(i);
  }
  return result;
}
