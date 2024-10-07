#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
  int x = 0;
  unordered_map<char, int> mpp;
  for (int i = 0; i < secret.length(); i++) {
    mpp[secret[i]]++;
  }
  int common = 0;
  unordered_map<char, int> set;
  for (int j = 0; j < guess.length(); j++) {
    set[guess[j]]++;
  }
  for (auto p : mpp) {
    if (set.find(p.first) != set.end()) {
      common += min(p.second, set[p.first]);
    }
  }
  for (int i = 0; i < secret.length(); i++) {
    if (secret[i] == guess[i]) {
      x++;
    }
  }

  string ans = "";
  ans += to_string(x) + 'A';
  ans += to_string(common - x) + 'B';
  return ans;
}
