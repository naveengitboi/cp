#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>


class Node{
public:
  int data;
Node *left, *right;
  Node(int data){
    this->data = data;
    left=right = nullptr;
  }
};

bool isLeafNode(Node* root){
  if(!root->left && !root->right){
    return true;
  }
  return false;
}
void leftBoundary(Node* root, vi& ans){
  Node* curr =root->left;
  while(curr){
    if(!isLeafNode(curr)){
      ans.push_back(curr->data);
    }
    if(curr->left) curr = curr->left;
    else curr = curr->right;
  }
}
void rightBoundary(Node* root, vi& ans){
  Node* curr = root->right;
  vi temp;
  while(curr){
    if(!isLeafNode(curr)){
      temp.push_back(curr->data);
    }
    if(curr->right) curr =curr->right;
    else curr = curr->left;
  }
  reverse(temp.begin(), temp.end());
  for(auto num: temp){
    ans.push_back(num);
  }
}
void leafNodes(Node* root,vi& ans){
  if(!root) return;
  if(isLeafNode(root)) ans.push_back(root->data);
  leafNodes(root->left, ans);
  leafNodes(root->right, ans);
}
vi boundaryTraversal(Node* root){
  vi  ans;
  if(!root) return {};
  if(!isLeafNode(root)) ans.push_back(root->data);
  leftBoundary(root,ans);
  leafNodes(root,ans);
  rightBoundary(root,ans);

  return ans;
}
