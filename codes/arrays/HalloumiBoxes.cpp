#include <bits/stdc++.h>
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

bool solve(vi &nums, int n, int k) {
  if (k == 1) {
    vi temp = nums;
    sort(nums.begin(), nums.end());
    if (temp != nums)
      return false;
    return true;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vi nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    bool ans = solve(nums, n, k);
    if (ans) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
