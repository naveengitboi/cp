#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long countSetBits(long long num){
  int cnt =0 ;
  while(num){
      if(num&1){
      cnt += 1;
    }
    num = num>>1;
  }

  return cnt;
}
long long countPairs(vector<int> nums, int k){

  set<int> unique;
  for(auto num: nums){
    unique.insert(num);
  }

  vector<long long> setBits;
  for(auto num: unique){
    long long bits = countSetBits(num);
    setBits.push_back(bits);
  }

  sort(setBits.begin(), setBits.end());

  long long result=0;

  long long l =0, r = setBits.size() -1, n = setBits.size() ;
  while(l <n && r>=0){
    if(setBits[l] + setBits[r] < k){
      l++;
    }
    else{
      result+= (n-l);
      r--;
    }
  }
  
  return result;


}

