#include <bits/stdc++.h>
#include <cmath>
#include <queue>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>



vvi createAdjList(int n,int p,  vector<pair<int, int>> prerequisites){

  vvi adj(n);

  for(int i =0; i< p; i++){
    int toComplete = prerequisites[i].second;
    int before = prerequisites[i].first;
    adj[toComplete].push_back(before);
  }
  
  return adj;
}



bool taskComplete(int n,int p, vector<pair<int, int>>prerequisites){
  
  vvi adj = createAdjList(n, p, prerequisites);
  vi indegrees(n, 0);
  queue<int>q;

  for(int i =0; i< adj.size(); i++){
    for(auto num : adj[i]){
      indegrees[num]++;
    }
  }
  
  for(int i =0; i< n; i++){
    if(indegrees[i] == 0){
      q.push(i);
    }
  }

  vi ans;
  while(!q.empty()){
    int x = q.front();
    ans.push_back(x);
    q.pop();
    for(auto num: adj[x]){
      indegrees[num]--;
      if(!indegrees[num]){
        q.push(num);
      }
    }
  }


  return ans.size() == n;

}
