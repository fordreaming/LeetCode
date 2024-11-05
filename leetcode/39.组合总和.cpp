// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, 0);
        return res;
    }

    void backTracking(const vector<int>& candidates, int target, int sum, int start_idx)
    {
        if (sum == target)
        {
            // 收集结果
            res.push_back(path);
            return;
        }
        
        if (sum > target)
        {
            return;
        }

        for (size_t i = start_idx; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};
// @lc code=end

