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

Node* deletionBST(Node* root, int target){

  if(!root) return nullptr;

  if(root->data < target){
    root->right = deletionBST(root->right,target);
    return root;
  }
  else if(root->data > target){
    root->left = deletionBST(root->left,target);
    return root;
  }
  if(!root->left){
    Node* temp = root->right;
    delete root;
    return temp;
  }
  else if(!root->right){
    Node* temp = root->left;
    delete root;
    return temp;
  }
  
  
  Node* curr = root->right;
  while(curr->left){
    curr = curr->left;
  }

  root->data = curr->data;
  root->right =deletionBST(root->right, curr->data);

  return root;
  
}

