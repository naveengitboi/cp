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


Node* lca(Node* root, Node* p, Node* q){
  if(!root || root == p || root == q){
    return root;
  }

  Node* left = lca(root->left, p, q);
  Node* right = lca(root->right, p, q);

  if(!left) return right;
  if(!right) return left;

  return root;
}
