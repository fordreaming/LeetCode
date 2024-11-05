// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
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
    bool isSymmetric(TreeNode* root) {
        // 1、递归法
        // 1.1 如果左右都为空，对称
        // 1.2 左右其中一个为空，不对称
        // 1.3 左右不相等，不对称
        // 1.4 左右相等，继续判断、左子树的外侧和右子树的外侧比较，左子树的内侧和右子树的内侧比较
        
        // if (root == nullptr)
        // {
        //     return true;
        // }

        // return isSym(root->left, root->right);

        // 2、迭代法,栈
        // 3、迭代法，队列
        queue<TreeNode*> que{};
        if (root != nullptr)
        {
            que.push(root->left);
            que.push(root->right);
        }

        while (!que.empty())
        {
            TreeNode* left_node = que.front();
            que.pop();

            TreeNode* right_node = que.front();
            que.pop();

            if (left_node == nullptr && right_node == nullptr)
            {
                continue;
            }
            else if (left_node == nullptr 
                     || right_node == nullptr 
                     || left_node->val != right_node->val)
            {
                return false;
            }
            else
            {
                que.push(left_node->left);
                que.push(right_node->right);
                que.push(left_node->right);
                que.push(right_node->left);
            }
        } 
        
        return true;
    }
};
// @lc code=end

