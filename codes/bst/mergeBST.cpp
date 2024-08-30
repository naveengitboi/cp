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

void pushLeft(Node* root, stack<Node*>& s){
  while(root){
    s.push(root);
    root = root->left;
  }
}


vector<int>  mergeBST(Node* root1, Node* root2){

  stack<Node*> st1;
  stack<Node*> st2;
  pushLeft(root1, st1);
  pushLeft(root2, st2);
  vector<int> ans;
 
  while(!st1.empty() || !st2.empty()){
    if(st1.empty() || (!st2.empty() && st2.top()->data < st1.top()->data)){
      Node* n2 = st2.top();
      ans.push_back(n2->data);
      st2.pop();
      if(n2->right){
        pushLeft(n2->right,st2); 
      }
    }else{

      Node* n1 = st1.top();
      ans.push_back(n1->data);
      st1.pop();
      if(n1->right){
        pushLeft(n1->right, st1);
      }
    }
  }
  return ans;
}

