// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem376.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    // 遍历、记录当前元素与前一个元素的差值，当前元素与后一个元素的差值，两个差值进行比较
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 2)
        {
            return 0;
        }
        
        int pre_diff = nums[1] - nums[0];

        int max_sub_len = 0;
        int res = 1;
        for (size_t i = 2; i < nums.size(); i++)
        {
            int cur_diff = nums[i] - nums[i-1];
            if (pre_diff * cur_diff < 0)
            {
                res++;
            }
            else
            {
                res = 0;
            }

            max_sub_len = max(max_sub_len, res);
            pre_diff = cur_diff;
        }
        
        max_sub_len = max(max_sub_len, res);
        return max_sub_len + 1;
    }
};
// @lc code=end

