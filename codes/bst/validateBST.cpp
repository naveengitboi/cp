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


bool validateBST(Node* root){
  
  bool ans = true;

  int mini = INT_MIN;
  int maxi = INT_MAX;
  inorder(root, mini, maxi, ans);
  return ans;
  
}

