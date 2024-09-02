#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define vvi vector<vector<int>>
#define ull unsigned long long

/* Main()  function */
int getDigitsSum(int num){
  int ans = 0;
  while(num){
    ans += num%10;
    num /= 10;
  }

  return ans;
}

int bestDivisor(int n){
  int sol = 0, ans = 0;
  for(int i = 1; i*i <= n; i++){
    if(n%i == 0){
      
      int sum = getDigitsSum(i);
      if(sol < sum){
        sol = sum;
        ans = i;
      }
      if(sol == sum){
        ans = min(ans, i);
      }
      if(i != n/i){
        int sum = getDigitsSum(n/i);
      if(sol < sum){
        sol = sum;
        ans = n/i;
      }
      if(sol == sum){
        ans = min(ans, n/i);
      }
      }
    }
  }
  return sol;
}

int main() {
  unsigned long long int n;
  cin >> n;
  cout<<bestDivisor(n)<<"\n";
  return 0;
}
/* Main() Ends Here */
