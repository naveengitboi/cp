#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
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

//leetcode 1335

int solve(int idx,int n, vi& jd, int d, vvi& dp){

  if(d == 1){
    int maxJd = jd[idx];

    for(int i = idx; i< n; i++){
      maxJd = max(maxJd,jd[i]);
    }

    return maxJd;
  }
  if(dp[idx][d] != -1){
    return dp[idx][d];
  }
  int maxD = jd[idx];
  int finalAns = INT_MAX;
  for(int i = idx ; i<= n-d; i++){
    maxD = max(jd[i], maxD);
    int result = maxD + solve(i+1, n, jd, d-1, dp);
    finalAns = min(finalAns, result);
  }

  return dp[idx][d] = finalAns;
}

int minJobDificulty(vi& jd, int d ){
  
  
  int n = jd.size();
  vvi dp(n+1, vi (d+1, -1));
  if(n < d ) return -1;

  return solve(0, n, jd, d, dp);
  
}
int main(){
  


  return 0;
}
