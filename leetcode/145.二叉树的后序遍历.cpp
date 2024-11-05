// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // 1、递归 左-右-根；
    // 2、迭代法；前序遍历-根-左-右：按根-右-左访问，然后逆序
    // 3、迭代法，统一风格；后序遍历：左-右-根

    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        
        vector<int> res{};
        stack<TreeNode*> stk{};
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode* cur_node = stk.top();
            if(cur_node != nullptr)
            {
                stk.pop();

                stk.push(cur_node);
                stk.push(nullptr);

                if (cur_node->right != nullptr)
                {
                    stk.push(cur_node->right);
                }
                
                if (cur_node->left != nullptr)
                {
                    stk.push(cur_node->left);
                }
            }
            else
            {
                stk.pop();
                cur_node = stk.top();
                stk.pop();

                res.push_back(cur_node->val);
            }
        }

        return res;
    }
};
// @lc code=end

