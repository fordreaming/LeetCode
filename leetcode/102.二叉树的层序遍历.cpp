// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem102.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 递归，采用队列进行处理
        vector<vector<int>> res{};
        recursive(root, res, 0);
        return res;
    }

    // 递归三步曲
    void recursive(TreeNode* root, vector<vector<int>>& res, int level)
    {
        // 终止条件
        if(root == nullptr)
        {
            return;
        }

        if (res.size() == level)
        {
            res.push_back({});
        }

        res[level].push_back(root->val);

        recursive(root->left, res, level + 1);
        recursive(root->right, res, level + 1);
    }
};
// @lc code=end

