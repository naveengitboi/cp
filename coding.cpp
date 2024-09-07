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

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int p;
    cin>>p;
    int g;
    for(int i = 0; i< n-1;i++){
      int q;
      cin>>q;
      g = __gcd(p, q);
      p = g;
    }
    if(g == 1) cout<< "YES";
    else cout<<"NO";
    
  }
  return 0;
}
/* Main() Ends Here */
