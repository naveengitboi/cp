#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define vvt vector<vector<int>>

void fillGrid(vvt &grid, int n, int m, vector<int> track) {
  int row = track[0];
  int colStart = track[1];
  int colEnd = track[2];

  for (int i = colStart - 1; i < colEnd; i++) {
    grid[row - 1][i] = 1;
  }
}

int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
  vvt grid(n, vector<int>(m, false));
  int ans = 0;

  for (int i = 0; i < track.size(); i++) {
    fillGrid(grid, n, m, track[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j])
        ans++;
    }
  }

  return ans;
}
