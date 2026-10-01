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

private:
    vector<int> travel (TreeNode* root)
    {
        if(root==nullptr)
        {
            return {0,0};
        }
        vector<int> left_node = travel(root->left);
        vector<int> right_node = travel(root->right);
        vector<int> options(2);

        options[0]=root->val + left_node[1]+right_node[1];

        options[1]= max(left_node[0],left_node[1])+max(right_node[0],right_node[1]);
        return options;

    }
public:
    int rob(TreeNode* root) {
        vector<int> options = travel(root);
        return max(options[0],options[1]);
    }
    
};