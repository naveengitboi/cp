#include <bits/stdc++.h>
using namespace std;

int bagoftokens(vector<int>& tokens, int  power){
  int ans;
  sort(tokens.begin(), tokens.end());
  int l =0, r = tokens.size()-1;

  int score = 0;
  while(l<=r){
    if(power >= tokens[l]){
      score ++;
      power -= tokens[l];
      l++;
    }
    else{
      if(score > 0){
        score -=1;
        power += tokens[r];
      }
        r--;
    }
    
    ans = max(ans, score);
  }


  return ans;
}
