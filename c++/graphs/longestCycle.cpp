#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int N = 1e5+5;
vector<int> g[N];
vector<int> height(N);

const int ACTIVE_NODE = 1;
const int EXPLORED_NODE = 2;

class Solution {
    void dfs (int src, int depth, vector<int>& visited, int& longest_cycle) {
        if (visited[src] == ACTIVE_NODE) {
            longest_cycle = max (longest_cycle, depth - height[src]);
            return;
        } 
        if (visited[src] == EXPLORED_NODE) return;
        
        visited[src] = ACTIVE_NODE;
        height[src] = depth;        
        
        for (auto i : g[src]) dfs (i, depth+1, visited, longest_cycle);
        
        visited[src] = EXPLORED_NODE;
    }
    
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        for (int j = 0; j < n; j ++) 
            if (edges[j] != -1) g[j].push_back(edges[j]);
        
        int result = -1;
        vector<int> visited (n, false);
        
        for (int j = 0; j < n; j ++) {
            dfs (j, 1, visited, result);
        }
        
        for (int j = 0; j < n; j ++) {
            height[j] = 0;
            g[j].clear();
        }
        return result;
    }
};


int main(){
  int n;
  cin>>n;
  vector<int> edges;
  for(int i = 0; i< n; i++){
    int node;
    cin>>node;
    edges.push_back(node);
  }

  auto ans =new Solution;
  int result = ans->longestCycle(edges);

  cout<<result;
  
  return 0;
}
