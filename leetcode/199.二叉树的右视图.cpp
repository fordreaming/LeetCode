// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem199.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        // 队列法，每一层取最后一个值
        vector<int> res{};
        queue<TreeNode*> que{};

        if (root != nullptr)
        {
            que.push(root);
        }
        
        while (!que.empty())
        {
            int size = que.size();
            for (size_t i = 0; i < size; i++)
            {
                TreeNode* cur_node = que.front();
                que.pop();

                if (i == size - 1)
                {
                    res.push_back(cur_node->val);
                }
                
                if (cur_node->left != nullptr)
                {
                    que.push(cur_node->left);
                }

                if (cur_node->right != nullptr)
                {
                    que.push(cur_node->right);
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

