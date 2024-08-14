#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int minCost(string colors, vi neededTime){
  int ans = 0;
  int prevColor = 0;

  for(int i =0; i< colors.size(); i++){
    if(i > 0 && colors[i] != colors[i-1]){
      prevColor = 0;
    }

    int curr = neededTime[i];
    ans += min(prevColor, curr);
    prevColor = max(curr, prevColor);
  }

  return ans;
}
