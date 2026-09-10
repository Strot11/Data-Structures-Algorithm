/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans = 0;
pair<int,int> solve(TreeNode* root){
    if(root == NULL) return {0,0};
   pair<int,int> left = solve(root->left);
   pair<int,int> right = solve(root->right);
    if(floor((root->val+left.first+right.first)/(left.second+right.second+1)) == root->val) ans++;
    return {(root->val+left.first+right.first),(left.second+right.second+1)};
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};