// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem55.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for (size_t i = 0; i <= cover; i++)
        {
            // cover  i + nums[i] 取最大
            int cur_fast_pos = i + nums[i];
            cover = max(cover, cur_fast_pos);

            if (cover >= nums.size() - 1)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

