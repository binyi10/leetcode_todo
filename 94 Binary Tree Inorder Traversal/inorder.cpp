/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> & vec)
    {
        if(root -> left != NULL)
        {
            inorder(root -> left,vec);
        }
        vec.push_back(root -> val);
        if(root -> right != NULL)
        {
            inorder(root -> right,vec);
        }
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root == NULL)return vec;
        inorder(root,vec);
        return vec;
    }
};