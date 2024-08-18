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

Node* insertion(Node* root, int target){
  if(!root) return new Node(target);
  Node* curr = root;
  while(true){
    if(curr->data > target){
      if(!curr->left){
        curr->left = new Node(target);
        break;
      }
      curr = curr->left;
    }
    else{
      if(!curr->right){
        curr->right = new Node(target);
        break;
      }
      curr = curr->right;
    }
  }

  return root;
  
}

