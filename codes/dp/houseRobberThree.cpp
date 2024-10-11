// @leet start

// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int idx, int n, vector<int>& nums){
        if(idx == 0){
            return nums[0];
        }
        if(idx == 1){
            return max(nums[1], nums[0]);
        }
        int take = nums[idx] + solve(idx-2,n, nums);
        int dontTake = solve(idx-1,n, nums);
        return max(take, dontTake);
    } 
    int rob(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> nums;
        while(!q.empty()){
            int len = q.size();
            int sum = 0;
            for(int i =0; i< len; i++){
                TreeNode* top = q.front();
                sum += top->val;
                q.pop();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            nums.push_back(sum);
        }
        int n = nums.size();
        int ans = solve(n-1, n, nums);

        return ans;
    }
};
// @leet end
