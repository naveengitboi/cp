#include <bits/stdc++.h>
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


vvi merge(vvi& intervals){
  vvi ans;

  sort(intervals.begin(), intervals.end());

  for(int i =0; i< intervals.size(); ++i){
    int start = intervals[i][0];
    int end = intervals[i][1];
    if(ans.empty() || ans.back()[1] <= start){
      ans.push_back({start, end});
    }
    else{
      ans.back()[1] = max(end, ans.back()[1]);
    }

  }

  return ans;
}

int eraseOverlapping(vvi& intervals){
  vvi merged = merge(intervals);
  int cnt = 0;


  return cnt ;
}
