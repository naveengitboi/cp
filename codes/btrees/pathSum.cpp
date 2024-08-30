#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int target, vvi &ans, vi path, int sum){
  if(!root) return;

  sum += root->val;
  path.push_back(root->val);

  if(!root->left && !root->right){
    if(sum == target){
      ans.push_back(path);
    }
    return;
  }

  dfs(root->left,target, ans, path , sum);
  dfs(root->right,target, ans, path , sum);

  return;
}

vvi pathSum(TreeNode* root, int targetSum){
  vvi ans;
  vi temp;
  dfs(root, targetSum, ans, temp, 0);
  return ans;
}
