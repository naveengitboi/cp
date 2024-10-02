#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

// tle
ll maxScore(vi &a, vi &b) {
  ll ans;
  int n = b.size();
  for (int i = 0; i + 4 < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          ll v = b[k] * a[2] + b[j] * a[1] + b[i] * a[0] + b[l] * a[4];
          ans = max(ans, v);
        }
      }
    }
  }
  return ans;
}


//Recursion take, not take

ll solve(int idx, int g, vi& a, vi& b){
    if(g == 4){
        return 0;
    }
    if(idx == b.size()){
        return -1e12;
    }
    ll nottake = solve(idx+1, g, a, b);
    ll take = solve(idx+1, g+1, a, b) + a[g]*1LL*b[idx];

    return max(take, nottake);
}



// Recursion + Memo

ll recursionMemo(int idx, int g, vi& a, vi& b, vector<vector<ll>> dp){
    if(g == 4){
        return 0;
    }
    if(idx == b.size()){
        return -1e12;
    }
    if(dp[idx][g] != -1e12){
        return dp[idx][g];
    }
    ll nottake = solve(idx+1, g, a, b);
    ll take = solve(idx+1, g+1, a, b) + a[g]*1LL*b[idx];

    return dp[idx][g] = max(take, nottake);
}


