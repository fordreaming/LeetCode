// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem226.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        // 1、递归法，递归法的中序遍历不可用，其余遍历可用
        // 2、迭代法1
        // 3、迭代法，栈标志法、统一写法
        // 
        // 前序 根-左-右
        queue<TreeNode*> que{};
        if (root != nullptr)
        {
            que.push(root);
        }

        while (!que.empty())
        {
            TreeNode* cur_node = que.front();
            que.pop();

            swap(cur_node->left, cur_node->right);
            if (cur_node->left != nullptr)
            {
                que.push(cur_node->left);
            }

            if (cur_node->right != nullptr)
            {
                que.push(cur_node->right);
            }
        }
        
        return root;
    }
};
// @lc code=end

