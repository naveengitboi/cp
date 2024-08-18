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

bool check(Node* root1, Node* root2){
  if(!root1 && !root2) return true;
  if(root1 && !root2) return false;
  if(!root1 && root2) return false;

  if(root1->data != root2->data){
    return false;
  }

  return check(root1->left, root2->right) && check(root1->right, root2->left);
}

bool symmetric(Node* root){
  if(!root) return true;

  return check(root->left, root->right);
}



