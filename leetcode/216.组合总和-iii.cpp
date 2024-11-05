// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem216.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 1, 0);
        return res;
    }

    void backTracking(int k, int n, int startIdx, int sum)
    {
        if (path.size() == k && sum == n)
        {
            res.push_back(path);
            return;
        }

        for (size_t i = startIdx; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backTracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
};
// @lc code=end

