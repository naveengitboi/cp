#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

vvi pascalTriangle(int n) {
  vvi ans;
  ans.push_back({1});
  for (int i = 1; i <= n; i++) {
    vector<int> temp;
    for (int j = 0; j <= i; j++) {
      int curr = 0;
      if (j - 1 >= 0) {
        curr += ans[i - 1][j - 1];
      }
      if (j <= i - 1) {
        curr += ans[i - 1][j];
      }
      temp.push_back(curr);
    }
    ans.push_back(temp);
  }

  return ans;
}
