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

class Solution {
public:
  vvi directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vvi heighestPeak(vvi &isWater) {
    int m = isWater.size();
    int n = isWater[0].size();
    vvi grid(m, vi(n, 1));

    vvi visited(m, vi(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isWater[i][j]) {
          grid[i][j] = 0;
        }
      }
    }
    auto isValid = [&](int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n;
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && visited[i][j] == 0) {
          for (auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (isValid(i_, j_) && isWater[i_][j_] == 0) {
              grid[i_][j_] = max(grid[i_][j_], grid[i][j] + 1);
            }
          }
        }
      }
    }

    return grid;
  }
};
