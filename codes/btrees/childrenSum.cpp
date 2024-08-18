#include <bits/stdc++.h>
#include <climits>
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

bool dfs(Node* root){
  if(!root->left && !root->right){
    return true;
  }
  if(!root->right && root->left){
    return root->data == root->left->data;
  }
  if(root->right && !root->left){
    return root->data == root->right->data;
  }
  if(root->data != root->left->data + root->right->data){
    return false;
  }
  bool left = dfs(root->left);
  bool right = dfs(root->left);
  
  return left&&right;
}

bool childrenSum(Node* root){

  return dfs(root);
}

