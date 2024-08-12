#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define vt vector<int>
#define vv vector<vector<int>>


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}

};

vv zizZag(Node* root){ 
  if(!root ) return {};
  vv result;
  bool dir = true;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    vt temp;
    for(int i =0; i<size; i++){
      Node* node = q.front();
      temp.push_back(node->data);
      q.pop();
      if(node->left){
        q.push(node->left);
      }

      if(node->right){
        q.push(node->right);
      }

      if(dir){
        result.push_back(temp);
      }else{
        reverse(temp.begin(), temp.end());
        result.push_back(temp);
      }
    }
    dir = !dir;
  }

  return result;

}
