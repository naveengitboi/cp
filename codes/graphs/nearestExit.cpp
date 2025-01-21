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
  vvi directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  int nearExit(vector<vector<char>> &maze, vector<int> &entrance) {

    int steps = 0;
    queue<pii> q;
    int m = maze.size();
    int n = maze[0].size();

    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';

    while (!q.empty()) {
      int N = q.size();
      while (N--) {
        auto temp = q.front();
        q.pop();
        int i = temp.first;
        int j = temp.second;

        if ((i == 0 || i == m - 1 || j == n - 1 || j == 0) &&
            (temp != make_pair(entrance[0], entrance[1]))) {
          return steps;
        }
        for (auto &dir : directions) {
          int i_ = i + dir[0];
          int j_ = j + dir[1];

          if ((i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) &&
              (maze[i_][j_] != '+')) {
            q.push({i_, j_});
            maze[i_][j_] = '+';
          }
        }
      }
      steps++;
    }

    return -1;
  }
};
