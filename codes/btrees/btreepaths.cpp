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

void dfs(Node* root, vv& ans, vt temp){
  if(!root){
    return;
  }
  temp.push_back(root->data);
  if(!root->left && !root->right){
    ans.push_back(temp);
    temp.clear();
  }

  dfs(root->left, ans, temp);
  dfs(root->right, ans, temp);
}

vv paths(Node* root){
  vv ans;
  vt temp;
  dfs(root, ans, temp);

  return ans;
}



