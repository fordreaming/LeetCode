// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0);

        return res;
    }

    void backTracking(vector<int>& nums, int startIdx)
    {
        res.push_back(path);

        if (path.size() > startIdx)
        {
            return;
        }
        
        size_t i = 0;
        for (i = startIdx; i < nums.size(); i++)
        {
            std::cout << "[in]  idx: " << i << std::endl;
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();

            int test = 0;
            std::cout << "[out]  idx: " << i << std::endl;
        }

        int test1 = 0;
    }
};
// @lc code=end

