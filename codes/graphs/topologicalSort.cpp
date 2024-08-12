#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void dfs(int cur, vector<vector<int>>adj, vector<int> & visited, stack<int>  &s){
  visited[cur] = 1;

  for(auto k: adj[cur]){
    if(!visited[k]){
      dfs(k, adj, visited, s);
    }
  }

  s.push(cur);

}


vector<int> topologicalSort(vector<vector<int>> adj ){
  int n = adj.size();
  vector<int> visited(adj.size(), 0);
  vector<int> ans;
  stack<int> s;

  for(int i = 0; i< n ; i++){
    if(!visited[i]){
      dfs(i, adj, visited, s);
    }
  }

  while(!s.empty()){
    int x = s.top();
    ans.push_back(x);
    s.pop();
  }

  return ans;
}




