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
  void doDfs(vvi &stones, vector<bool> &visited, int index) {
    visited[index] = true;
    for (int i = 0; i < stones.size(); i++) {
      int r = stones[i][0];
      int c = stones[i][1];
      if (visited[i] == false &&
          (stones[index][0] == r || stones[index][1] == c)) {
        doDfs(stones, visited, i);
      }
    }
  }
  int removeStones(vvi &stones) {
    int n = stones.size();
    int groups = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      if (visited[i] == false) {
        doDfs(stones, visited, i);
        groups++;
      }
    }

    return n - groups;
  }
};
