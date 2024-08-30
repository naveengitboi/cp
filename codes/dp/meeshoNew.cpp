#include <bits/stdc++.h>
using namespace std;

int solve(string &s2, int n, int x, int y) {
  string s(s2.begin(), s2.end());
  
  vector<int> prevSame(s.size(),0);
  int idxL = -1, idxR = -1;
  for(int i = 0; i< s.size(); i++){
    if(s[i] == 'l'){
        prevSame[i] = idxL; 
      idxL = i;
    }
    else{
        prevSame[i] = idxR; 
      idxR = i;
    }
  }

  vector<vector<int>> dp(s.size(), vector<int> (n+1, 0));

  dp[0][x] = 1;
  
  for(int i = 1; i<=s.size() ; i++){
    for(int j = 0; j<= n ; j++){
      dp[i][j] = dp[i-1][j];
      if(s[i-1] == 'l' ){
        if(j+1<= n){
          dp[i][j] += dp[i-1][j-1];
        }
          if(j + 1 <= n && prevSame[i - 1] >= 0)
            dp[i][j] -= dp[prevSame[i - 1] + 1 - 1][j + 1];
      }else{
        if(j-1>= 0){
          dp[i][j] += dp[i-1][j-1];
        }
        if(j-1>=0  && prevSame[i-1] >= 0){
          dp[i][j] -= dp[prevSame[i - 1] + 1 - 1][j - 1];
        }

      }
    }
  }
}
