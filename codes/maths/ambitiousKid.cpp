#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>

int main() {
  int n;
  cin >> n;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp < 0) {
      temp = abs(temp);
    }
    ans = min(temp, ans);
  }
  cout << ans << endl;
  return 0;
}
