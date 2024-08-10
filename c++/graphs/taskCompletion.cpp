#include <bits/stdc++.h>
#include <cmath>
#include <queue>
using namespace std;


vector<vector<int>> createAdjacentList(int n , int p , vector<pair<int,int>> prerequisites){
  
  vector<vector<int>> adj;

  for(int i =0; i<p; i++){
    int node = prerequisites[i].second;
    adj[node].push_back(prerequisites[i].first);
  }

  return adj;

};

bool taskCompletion(int n, int P, vector<pair<int,int>> &prerequisites){

  vector<vector<int>> adj = createAdjacentList(n, P, prerequisites);
      
  vector<int> indegrees(n, 0);
  vector<int> ans;
  queue<int> que;

  //get indegrees
  for(int i = 0; i<n ; i++){
    for(auto node: adj[i]){
       indegrees[node] += 1;
    }
  }

  //get zeros

  for(int i = 0; i< n; i++ ){
    if(indegrees[i] == 0){
      que.push(i);
    }
  }


  while(!que.empty()){
      int x = que.front();
      ans.push_back(x);
      que.pop();

    for(auto it: adj[x]){
      indegrees[x] --;
      if(indegrees[x] == 0){
        que.push(x);
      }
    }
    
  }

  return ans.size() == n;

      
}


