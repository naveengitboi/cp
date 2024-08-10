#include <bits/stdc++.h>
#include <cmath>
using namespace std;


bool kahnsAlgo(vector<vector<int>> adj){
  int n = adj.size();
  vector<int> indegrees(n,0);
  
  vector<int> ans;
  queue<int> que;
  
  for(int i =0; i<n;i++){
    for(auto node: adj[i]){
      indegrees[node] += 1;

    }
  }

  for(int i =0; i< n; i++){
    if(indegrees[i] == 0){
      que.push(i);
    }
  }


  while(!que.empty()){
    int x = que.front();
    que.pop();
    ans.push_back(x);
    for(auto node: adj[x]){
      indegrees[node] -= 1;
      if(indegrees[node] == 0){
        que.push(node);
      }
    }

  }

  return ans.size() != n;

}
