// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // 1、递归法，根-左-右
    // 2、递归法，栈
    // 3、递归法，栈，统一写法
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        
        stack<TreeNode*> stk{};
        stk.push(root);
        vector<int> res{};

        while (!stk.empty())
        {
            TreeNode* cur_node = stk.top();
            if (cur_node != nullptr)
            {
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
                stk.push(nullptr);
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

