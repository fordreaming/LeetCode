// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "commoncppproblem491.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        return res;
    }

    void backTracking(vector<int>& nums, int start_idx)
    {
        if (path.size() >= 2)
        {
            res.push_back(path);
        }
        
        // 同一父节点，本层重复使用
        unordered_set<int> unset{};
        for (size_t i = start_idx; i < nums.size(); i++)
        {            
            // 去重
            if (!path.empty() && nums[i] < path.back())
            {
                continue;
            }

            if (unset.find(nums[i]) != unset.end())
            {
                continue;
            }
            
            unset.insert(nums[i]);
            
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

