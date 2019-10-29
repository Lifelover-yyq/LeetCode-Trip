/*
翻转一棵二叉树。
递归的在左右节点上不断执行左右节点翻转的操作。
*/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left != NULL || root->right != NULL) {//加入判断，若均为NULL则不翻转，稍微提高运行速度
            auto temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
