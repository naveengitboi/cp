#include <bits/stdc++.h>
#include <math.h>
using namespace std;


vector<int> solve(vector<int> arr){
  int n = arr.size();
  vector<int> ans(n);
  int pos = 0, neg = 1;
  for(int i =0; i< n;i++){
    if(arr[i] < 0){
      ans[neg] = arr[i];
      neg+=2;
    }else{
      ans[pos] = arr[i];
      pos += 2;
    }
  }
  return ans;
}
