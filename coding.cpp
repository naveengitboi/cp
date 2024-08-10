#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int data, Node* next): data(data), next(next) {};
  Node(int data) : data(data), next(nullptr) {};
};

// >n/2 problem moore voting algorithm
class solution {

public: 
  bool dfs(int k, vector<int>* adj, vector<int>& path, vector<int>& visited)
{
    visited[k] = 1;
      path[k] = 1;

      for(auto each: adj[k]){
        if(!visited[each]){
          if(dfs(each, adj, path, visited)) {
            return true;
         }
        }
        else if(path[k]){
        return true;
        }
    }

    path[k]= 0;
      
    return 0;
  }
  bool cycle(vector<int>*adj, int n){
    
    vector<int> path(n, 0), visited(n, 0);
    for(int i =0; i< n ; i++){
      if(!visited[i]){
        if(dfs(i, adj, path, visited)){
          return true;
        }
      }
    }

    return 0;
  }

};
