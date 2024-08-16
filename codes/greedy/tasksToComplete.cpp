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
int minRounds(vi& tasks){
  int ans= 0;
  mii mp;

  for(int num: tasks){
    mp[num]++;
  }

  for(auto &p: mp){
    cout<<p.first <<"\t" << p.second<<endl;
    if(p.second == 1){
      return -1 ;
    }
    else{
      int multi = p.second/3;
      int rem = p.second - multi*3;
      ans += multi;
      if(rem) ans += 1;
    }
  }

  return ans;
}
int main(){
  
  vi tasks = {2,2,2,3,3,4,4};
  int ans =  minRounds(tasks);
  cout<<ans<<endl;

  return 0;
}
