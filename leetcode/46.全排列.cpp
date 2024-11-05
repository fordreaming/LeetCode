// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem46.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    // 1.回溯法
    // 1）回溯有参数；
    // 2）递归终止条件；
    // 3）单层搜索的逻辑；
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return res;
    }

    void backTracking(vector<int>& nums, vector<bool>& used) {
        if(path.size() == nums.size())
        {
            res.push_back(path);
        }

        if(path.size() > nums.size())
        {
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if(used[i])
            {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end

