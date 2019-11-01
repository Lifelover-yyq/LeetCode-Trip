/*
给定两个二叉树，需要将他们合并为一个新的二叉树。
合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则，不为 NULL 的节点将直接作为新二叉树的节点。
*/

//递归操作，很简单，将其中一棵树作为结果树进行合并即可
//两树均NULL返回NULL，一棵为NULL则返回另外一棵

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return NULL;
        else if(t1 == NULL) return t2;
        else if(t2 == NULL) return t1;
        else {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
        }
        return t1;
    }
};
