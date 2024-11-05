// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem107.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 层次遍历
        vector<vector<int>> res{};
        queue<TreeNode*> que{};

        if (root != nullptr)
        {
            que.push(root);
        }
        
        while (!que.empty())
        {
            int size = que.size();

            vector<int> vec{};
            for (size_t i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);

                if (node->left != nullptr)
                {
                    que.push(node->left);
                }

                if (node->right != nullptr)
                {
                    que.push(node->right);
                }
            }

            res.push_back(vec);
        }
        
        // 翻转
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

