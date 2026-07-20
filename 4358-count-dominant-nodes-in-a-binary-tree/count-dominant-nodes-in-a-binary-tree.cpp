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
int solve(TreeNode* root,int &count){
    if(root == NULL) return 0;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    leftMax = max(leftMax,solve(root->left,count));
    rightMax = max(rightMax,solve(root->right,count));
    if(root->val >= max(leftMax,rightMax)) count++;
    return max({root->val,leftMax,rightMax});
}
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        int a = solve(root,cnt);
        return cnt;
    }
};