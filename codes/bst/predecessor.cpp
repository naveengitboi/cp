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

void inorder(Node* root, int& mini, int& maxi, bool& ans){
  if(!root) return;
  
   inorder(root->left, mini , root->data, ans);

  if(root->data <= mini || root->data >= maxi) {
    ans = false;
  }

   inorder(root->right, root->data, maxi, ans);
}

Node* getPred(Node* root, int target){
  Node* temp = nullptr;

  while(root){
    if(root->data < target){
      temp = root;
      root = root->right;
    }else{
      root = root->left;
    }
  }
  return temp;
}
Node* getSuccessor(Node* root, int target){
  Node* temp = nullptr;
  while(root){
    if(root->data <= target){
      root = root->right;
    }else{
      temp = root;
      root = root->left;
    }
  }

  return temp;
}

Node* predecessor(Node* root, int target){

  return getPred(root,target);
}

