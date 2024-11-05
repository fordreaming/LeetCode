// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 1、暴力解法        
        // 2、贪心解法，当和<=0的时候，立刻放弃，从下一个元素重新计算连续和
        int res{INT_MIN};
        int sum{0};

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum > res)
            {
                res = sum;
            }

            if (sum <= 0)
            {
                sum = 0;
            }
        }
        
        return res;
    }
};
// @lc code=end

