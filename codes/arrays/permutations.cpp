#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>


void solve(vvi& ans, vi& nums, vi& visited, vi& curr){
  if(curr.size() == nums.size()){
    ans.push_back(curr);
    return;
  }
  for(int i = 0; i<nums.size(); i++){
    if(!visited[i]){
      visited[i] = true;
      curr.push_back(nums[i]);
      solve(ans, nums, visited, curr);
      curr.pop_back();
      visited[i] = false;
    }
  }

  return;
}
