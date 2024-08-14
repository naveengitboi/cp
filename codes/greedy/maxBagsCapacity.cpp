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

int maxCapacity(vi& capacity, vi& rocks, int additionalRocks){
  
  int result = 0;
  vvi stonesWithCapacity;

  for(int i = 0; i< capacity.size(); i++){
    stonesWithCapacity.push_back({capacity[i], rocks[i]});
  }

  auto comp = [](vi& a, vi&b){
    if(a[0] == b[0]){
      return a[1] > b[1];
    }
    return a[0] < b[0];
  };

  sort(stonesWithCapacity.begin(), stonesWithCapacity.end(), comp);

  for(int i =0; i< capacity.size(); i++){
    int bagCapacity = stonesWithCapacity[i][0];
    int stones = stonesWithCapacity[i][1];

    if(stones == bagCapacity){
      result++;
    }else {
      if(additionalRocks>0){
        additionalRocks -= (bagCapacity - stones);
        result++;
      }
    }

  }
  return result;

}
