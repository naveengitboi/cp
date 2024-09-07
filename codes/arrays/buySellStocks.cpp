#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define vvt vector<vector<int>>
#define vt vector<int>


int maxProfit(vt prices){
  int n = prices.size();

  vt dp(n, 0);
  
  for(int i =1; i< n; i++){
    int profit = prices[i] - prices[i-1];
    dp[i] = max(profit + dp[i-1], dp[i-1]);
  
  }

  return dp[n-1];
}
