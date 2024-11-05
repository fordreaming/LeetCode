// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        
        backTracking(nums, 0, used);

        return res;
    }

    void backTracking(vector<int>& nums, int start_idx, vector<bool>& used) {
        res.push_back(path);

        if (start_idx >= nums.size())
        {
            return;
        }

        for (size_t i = start_idx; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            {
                continue;
            }
            
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end

