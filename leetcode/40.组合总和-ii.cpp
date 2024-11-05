// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);

        backTracking(candidates, target, 0, 0, used);

        return res;
    }

    void backTracking(vector<int>& candidates, int target, int sum, int start_idx, vector<bool>& used)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        if (sum > target)
        {
            return;
        }
        
        for (size_t i = start_idx; i < candidates.size(); i++)
        {
            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
            {
                continue;
            }
            
            path.push_back(candidates[i]);
            sum += candidates[i];

            used[i] = true;
            backTracking(candidates, target, sum, i + 1, used);
            used[i] = false;

            sum -= candidates[i];
            path.pop_back();
        }
    }
};
// @lc code=end

