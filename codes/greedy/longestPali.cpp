#include <bits/stdc++.h>
#include <string>
#include <sys/types.h>
#include <unordered_map>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define vs vector<string> 

int longestPalindrome(vs& words){
  int result = 0;
  unordered_map<string, int> mp;

  for(string& word: words){
    mp[word]++;
  }
  bool centerClosed = false;
  for(string& word: words){
    string original = word;
    string rev = word;
    reverse(rev.begin(), rev.end());
    if(word != rev){
      if(mp[word] > 0 && mp[rev] > 0){
        result += 4;
        mp[word]--;
        mp[rev]--;
      }
    }
    else{
      if(mp[word] >= 2){
        result += 4;
        mp[word]-=2;
      }
      else{
        if(mp[word] == 1 && centerClosed == false){
          result += 2;
          mp[word]--;
          centerClosed = true;
        }
      }
    }
  }

  return result;

}
