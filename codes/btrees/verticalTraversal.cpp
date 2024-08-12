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
vv verticalTraversal(Node* root){
  vv ans;

  map<int, map<int , vt>> mp;
  queue<pair<Node*, pair<int, int>>> q;

  q.push({root, {0,0}});

  while(!q.empty()){
    Node* curr = q.front().first;
    int currRow = q.front().second.first;
    int currCol = q.front().second.second;
    q.pop();

    mp[currCol][currRow].push_back(curr->data);

    if(curr->left){
      q.push({curr->left, {currRow+1, currCol-1}});
    }
    if(curr->right){
      q.push({curr->right, {currRow+1, currCol+1}});
    }

  }


  for(auto c: mp){
    vt temp1;
    for(auto r: c.second){
      vt temp2 = r.second;
      sort(temp2.begin(), temp2.end());
      temp1.insert(temp1.end(), temp2.begin(), temp2.end());
    }

    ans.push_back(temp1);

  }


  return ans;
}



