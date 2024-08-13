#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string> 

void dfs(int curr, vi& visited, stack<int>&s, vvi& adj){

  visited[curr] = 1;
  for(auto node: adj[curr]){
    if(visited[node] == 0){
      dfs(node, visited, s, adj);
    }
  }

  s.push(curr);
}
vi topologicalSort(vvi& adj, int n){
  stack<int> s;
  vi visited(n, 0);
  for(int i = 0; i<n; i++){
    if(!visited[i]){
      dfs(i, visited, s, adj);
    }
  }
  vi ans;

  while(!s.empty()){
    int x = s.top();
    ans.push_back(x);
    s.pop();
  }

  return ans;
}

string alianDict(int n, int k, vs& words ){
  string ans;
  vvi adj;

  for(int i =0; i<n-1; i++){
    string w1 = words[i];
    string w2  = words[i+1];

    int minLen = min(w1.size(),  w2.size());
    int j = 0;
    while(j < minLen){
      if(w1[j] != w2[j]){
        adj[w1[j] - 'a'].push_back(w2[j] - 'a');
        break;
      }
      j--;
    }
  }

  vi topoSort = topologicalSort(adj, n);

  for(int i = 0; i<n; i++){
    ans += (topoSort[i] + 'a');
  }

  return ans;

}


int main(){

  vs words = {"baa", "aaa", "aac"};
  int n = 3;
  int k = 3;

  string ans = alianDict(n, k, words);
  cout<<ans;

  return 0;
}
