#include <bits/stdc++.h>
#include <cmath>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}

};

int dfs(Node* root,  int& result){
  if(!root){
    return 0;
  }
  int left = dfs(root->left, result);
  if(left < 0){
    return 0;
  }
  int right = dfs(root->right, result);
  if(right< 0){
    return 0;
  }
  result = max(result, root->data + left + right);

  return root->data + max(left, right);

}

int maxPathSum(Node* root){

  if(!root) return 0;
  int result = 0;

  dfs(root, result);
  return result;

}
