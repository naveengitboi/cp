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

int solve(int n, vector<int>&dp){
  if(n == 0) return 0;
  int miniValue= INT_MAX;
  if(dp[n] != -1){
    return dp[n];
  }
  for(int i = 1; i*i <= n; i++){
    int temp = 1 + solve(n - i*i, dp);
    miniValue = min(miniValue, temp);
  }

  return dp[n] = miniValue;
}

int minSqrs(int n){
  vector<int>dp(n+1, -1);
  return solve(n, dp);
  
}
int main(){
  


  return 0;
}
