#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HelloWorld {
public:
  static const int MOD = 1000000007;

  static int solve(const string &s2, int n, int x, int y) {
    // Creating array of string length
    vector<char> s(s2.begin(), s2.end());

    vector<int> prevSame(s.size());
    int idxL = -1;
    int idxR = -1;
    for (int i = 0; i < prevSame.size(); i++) {
      if (s[i] == 'l') {
        prevSame[i] = idxL;
        idxL = i;
      } else {
        prevSame[i] = idxR;
        idxR = i;
      }
    }

    // dp[i][j] is number of distinct subsequences of length i to end up at j
    vector<vector<long long>> dp(s.size() + 1, vector<long long>(n + 1, 0));
    dp[0][x] = 1;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = dp[i - 1][j];
        if (s[i - 1] == 'l') {
          if(j + 1 <= n)
            dp[i][j] += dp[i - 1][j + 1];
          if(j + 1 <= n && prevSame[i - 1] >= 0)
            dp[i][j] -= dp[prevSame[i - 1] + 1 - 1][j + 1];
        } else {
          if(j - 1 >= 0)
            dp[i][j] += dp[i - 1][j - 1];
          if(j - 1 >= 0 && prevSame[i - 1] >= 0)
            dp[i][j] -= dp[prevSame[i - 1] + 1 - 1][j - 1];
        }
        dp[i][j] = (dp[i][j] + MOD) % MOD;
      }
    }
    return static_cast<int>(dp[s.size()][y]);
  }
};

int main() {
  cout << HelloWorld::solve("rrlrlr", 6, 1, 3) << endl;
  return 0;
}
