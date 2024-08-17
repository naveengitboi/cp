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
#define vmp vector<unordered_map<int, int>>
//leetcode 446 hard

int numberOfArithmetics(vi& nums){
  int n = nums.size();
  unordered_map<long, int> dp[n];

  int cnt = 0;
  for(int i = 1; i< n; i++){
    for(int j =0; j<i; i++){
      long cd =(long)nums[i] - nums[j];
      if(dp[j].find(cd) == dp[j].end()){
        dp[i][cd]++;
      }
      else{
        cnt += dp[j][cd];
        dp[i][cd] += dp[j][cd] + 1;
      }
    }
  }
  return cnt;
}
int main(){
  


  return 0;
}
