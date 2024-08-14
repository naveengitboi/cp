#include <bits/stdc++.h>
#include <sys/types.h>
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


int bloomTime(vi& plantTime, vi& growTime){

  int ans = 0;
  int n = plantTime.size();
  vvi plantAndGrow(n);

  for(int i = 0; i<n; i++){
    plantAndGrow.push_back({plantTime[i], growTime[i]});
  }

  auto comp = [](vi& a, vi&b){
    return a[1] > b[1];
  };
  sort(plantAndGrow.begin(), plantAndGrow.end(), comp);

  int prevPlantDays = 0;
  int bloomDuration = 0;
  
  for(int i = 0; i< n; i++){
    int plantDays = plantAndGrow[i][0];
    int growDuration = plantAndGrow[i][1];
    prevPlantDays += plantDays;
    int currBloomTime = prevPlantDays + growDuration;
    bloomDuration = max(bloomDuration, currBloomTime);
  }

  return bloomDuration;

}
