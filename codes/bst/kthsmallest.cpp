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

void inorder(Node* root,int& ans , int& cnt, int& k){
  if(!root) return;
  inorder(root->left, ans, cnt, k );
  cnt ++;
  if(cnt == k){
    ans = root->data;
  }
  inorder(root->right, ans, cnt, k);

  return ;
}

int kthSmallest(Node* root, int k){

  int cnt = 1;
  int ans = -1;
  inorder(root,ans,cnt, k);
  return ans;
  
  
}

