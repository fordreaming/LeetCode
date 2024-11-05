// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem104.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
// 1、递归法 全局result  深度：从根到当前节点
// 2、迭代法，前序遍历，根-左-右，不可用
// 3、迭代法，统一风格
// 3、迭代法，层序遍历
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> stk{};
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode* cur_node = stk.top();
            stk.pop();

            if (cur_node->right != nullptr)
            {
                stk.push(cur_node->right);
            }
            
            if (cur_node->left != nullptr)
            {
                stk.push(cur_node->left);
            }

            stk.push(cur_node);
            
        }
        
        return 0;
    }
};
// @lc code=end

