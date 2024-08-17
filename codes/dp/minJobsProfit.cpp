
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

//leetcode i235 hard

int getNext(vvi& arr , int idx, int currEnd){
  int l = idx;
  int r = arr.size()-1;
  int ans = arr.size()+1;
  while(l <= r ){
    int mid = l + (r-l)/2;
    
    if(arr[mid][1] >= currEnd){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return ans;
}

int solve(vvi& arr, int curr, int profit){

  if(curr >= arr.size()){
    return 0;
  }

  int nextIdx = getNext(arr, curr+1, arr[curr][1]);

  int taken = arr[curr][2] + solve(arr, nextIdx, profit);
  int notTaken = solve(arr, curr+1, profit);
  return max(taken , notTaken);
}

int jobScheduling(vi& startTime, vi& endTime, vi& profit){
  
  int n = startTime.size();
  vvi arr(n);

  for(int i = 0; i< n; i++){
    arr.push_back({startTime[i], endTime[i], profit[i]});
  }

  auto comp = [](vi& a , vi& b ){
    return a[0] <= b[0];
  };
  sort(arr.begin(), arr.end(), comp);

  return solve(arr, 0, 0);
}
int main(){
  


  return 0;
}
