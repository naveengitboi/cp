#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define vt vector<int>
const int N = 1e5+5;
vt g[N];
vt height(N);


void dfs(int curr,vt& edges, vt &path, vt&visited, int depth, int result){
  
  if(visited[curr] and !path[curr]){
      result = max(result, depth-height[curr]);
    return;
  }
  if(visited[curr] and path[curr]){
    result = max(result, depth-height[curr]);
  }

  visited[curr] = true;
  path[curr] = 1;

  for(auto node: g[curr] ){
    dfs(node, edges, path, visited, depth+1, result);
  }

  path[curr] = 0;
}

int longestCylce(vt&edges){
  int n = edges.size();
  for(int i = 0 ; i< n; i++){
    if(edges[i]!= -1){
      g[i].push_back(edges[i]);
    }
  }

  int result = -1;
  vt visited(n, false);
  vt path(n, 0);

  for(int j = 0; j<n; j++){
    dfs(j, edges, path, visited, 1, result);
  }

  for(int j = 0; j< n; j++){
    height[j] = 0;
    g[j].clear();
  }

  return result;
  
};


int main(){
  int n;
  cin>>n;
  vt edges;
  for(int i = 0; i< n; i++){
    int node;
    cin>>node;
    edges.push_back(node);
  }

  int ans = longestCylce(edges);

  cout<<ans;
  
  return 0;
}
