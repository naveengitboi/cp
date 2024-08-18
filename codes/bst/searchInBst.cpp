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

Node* search(Node* root, int target){
  while(root){
    if(root->data ==  target){
      return root;
    }
    else if(root->data > target){
      root = root->left;
    }else{
      root = root->right;
    }
  }

  return nullptr;
  
}

