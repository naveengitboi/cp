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

ull primeCount(ull n){
  ull cnt;
  ull prod;
  ull prime;

  if( n<=1) return 0;

  prod = 2;
  cnt = 1;

  for(prime = 3; prime*prod  <= n; prime+=2){
    if(__gcd(prime, prod) == 1){
      cnt++;
      prod = prod*prime;
    }
  }

  return cnt;
}

int main() {
  unsigned long long int n;
  cin >> n;
  while(n){
    ull q;
    cin >> q;
    cout<<primeCount(q) << "\n";
    n--;
  }
  
  return 0;
}
/* Main() Ends Here */
