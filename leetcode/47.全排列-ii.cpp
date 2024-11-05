// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem47.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> nums_aux(nums);

        sort(nums_aux.begin(), nums_aux.end());

        backTracking(nums_aux, used);

        return res;
    }

    void backTracking(const vector<int>& nums, vector<bool>& used)
    {
        if (nums.size() == path.size())
        {
            res.push_back(path);
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (used[i] == true)
            {
                continue;
            }

            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
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

