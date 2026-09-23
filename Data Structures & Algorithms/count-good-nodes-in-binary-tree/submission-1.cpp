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
    int goodNodes(TreeNode* root) {
        return helper(root,0,INT_MIN);       
    }
private:
    int helper(TreeNode* root , int ans , int curMax)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int rootAnswer = 0;
        if(root->val >= curMax)
        {
            rootAnswer =1;
            curMax = root->val;
        }
        int lans = helper(root->left, ans,curMax);
        int rans = helper(root->right, ans,curMax);
        return lans+rans+rootAnswer;
    }
};
