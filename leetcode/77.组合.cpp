// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};                      // 收集总结果
    vector<int> path{};                             // 收集每一个路径的结果

    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);

        return res;
    }

    void backTracking(int n, int k, int startIdx)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (size_t i = startIdx; i <= n - (k-path.size()) + 1; i++)
        {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

