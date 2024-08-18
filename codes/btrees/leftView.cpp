#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define vv vector<vector<int>>
#define vt vector<int>

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(): data(0), left(nullptr), right(nullptr){}
  Node(int x): data(x), left(nullptr), right(nullptr){}
  Node(int x, Node* left, Node*right): data(x), left(left), right(right){}
  
};
vt verticalTraversal(Node* root){
  vt ans;

  if(!root) return ans;
  map<int, int> mp;
  queue<pair<Node*, pair<int,int>>> q;
  q.push({root,{0,0}});
  while(!q.empty()){
    Node* curr = q.front().first;
    int row = q.front().second.first;
    int col = q.front().second.second;
    q.pop();
    if(mp.find(row) == mp.end()){
      mp[row] = curr->data;
    }

    if(curr->left){
      q.push({curr->left, {row+1, col-1}});
    }
    if(curr->right){
      q.push({curr->right, {row+1, col+1}});
    }
    
  }


  for(auto &c:mp){
    ans.push_back(c.second);
  }

  return ans;
  
}



