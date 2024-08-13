#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>


string subStr(int idx,int& len, string &s){
  string ans;
  for(int k = idx; k <len; k++){
    ans += s[k];
  }
  return ans;
}


vi getSubStringIdx(vector<string>words, string s){
  vi ans;
  map<string, int> mp;

  for(auto word : words){
    mp[word]++;
  }

  int k = words[0].length();

  for(int i = 0;s.length(); i++ ){
    map<string, int> cp = mp;
    int len = k;
    int j = i;
    while(j<s.length()){
      string sub = subStr(j, k, s);
      if(cp.find(sub) == cp.end()){
        break;
      }
      else{
        if(cp[sub] == 1){
          cp[sub]--;
        }else{
          break;
        }
      }
      j += len;
    }
    

  }

  return ans;
}
