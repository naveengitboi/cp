#include <bits/stdc++.h>
#include <climits>
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



int maxWidth(Node* root){
  queue<pair<Node*, int>> q;
  q.push({root,0});
  int maxi = 0;

  while(!q.empty()){
    int len = q.size();
    int minLeft = INT_MAX;
    int maxRight = -INT_MAX;
    for(int i =0; i< len; i++){
        Node* curr = q.front().first;
        int idx = q.front().second;
      q.pop();
      minLeft = min(minLeft, idx);
      maxRight = max(maxRight, idx);

      if(curr->left){
        q.push({curr->left, 2*idx+1});
      }
      if(curr->right){
        q.push({curr->right, 2*idx+2});
      }
    }
    maxi = max(maxi, maxRight - minLeft + 1);
  }
  return maxi;

}
