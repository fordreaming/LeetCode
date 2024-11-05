// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem94.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res{};
        // 中序遍历 左-根-右
        // 标记法进行中序遍历
        // 需要加入nullptr进行标志

        stack<TreeNode*>   stk{};
        
        if (root != nullptr)
        {
            stk.push(root);
        }

        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            if (node != nullptr)
            {
                stk.pop();
                if (node->right != nullptr)
                {
                    stk.push(node->right);
                }

                stk.push(node);
                stk.push(NULL);

                if (node->left != nullptr)
                {
                    stk.push(node->left);
                }
            }
            else
            {
                stk.pop();
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
            
        }
        
        return res;
    }
};
// @lc code=end

