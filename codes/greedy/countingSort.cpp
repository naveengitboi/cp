#include <algorithm>
#include <bits/stdc++.h>
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

//my approach
void countingSort(vi& arr){
  int maxi = *max_element(arr.begin(), arr.end());
  vi cSum(maxi, 0);

  for(int num: arr){
    cSum[num]++;
  }

  for(int i =1; i< cSum.size();i++){
    cSum[i] = cSum[i] + cSum[i-1];
  }

  int left = 0;
  for(int i =0; i<cSum.size(); i++)
  {
    int right = cSum[i];
    if(right == 0 or right == left){
      continue;
    }

    while(left < right){
      arr[left] = i;
      left++;
    }
  }
  
}
int main(){
  
  vi tasks = {5,1,4,1,2,1,3,4,7,8};

  countingSort(tasks);
  for(auto num: tasks){
    cout<<num << "\t";
  }

  return 0;
}
