// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <numeric>
#include <functional>
#include <algorithm>
#include "commoncppproblem1005.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 1. 按照绝对值从大到小进行排序
        auto compareVal = [](int a, int b)
        {
            return abs(a) > abs(b);
        };

        std::sort(nums.begin(), nums.end(), compareVal);
        for (size_t i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        
        // 2. 如果k > 0, 对最后的数据进行修改
        if(k%2)
        {
            nums[nums.size() - 1] *= -1;
        }

        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return sum;
    }
};
// @lc code=end

