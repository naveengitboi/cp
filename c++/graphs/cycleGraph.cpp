#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data, Node *next) : data(data), next(next){};
  Node(int data) : data(data), next(nullptr){};
};

class solution {

public:
  bool dfs(int k, vector<int> *adj, vector<int> &path, vector<int> &visited, vector<int> ans) {
    visited[k] = 1;
    path[k] = 1;

    for (auto each : adj[k]) {
      if (!visited[each]) {
        if (dfs(each, adj, path, visited, ans)) {
          return true;
        }
      } else if (path[k]) {
        return true;
      }
    }

    path[k] = 0;
    ans.push_back(k);

    return 0;
  }
  bool cycle(vector<int> *adj, int n) {

    vector<int> ans; 
    vector<int> path(n, 0), visited(n, 0);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, adj, path, visited, ans);
      }
    }

    return 0;
  }
};
