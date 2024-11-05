/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        vector<int> nums_aux(nums);
        sort(nums_aux.begin(), nums_aux.end());
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            auto pos = std::find(nums_aux.begin(), nums_aux.end(), num);
            int less_num_count = std::distance(nums_aux.begin(), pos);

            res[num] = less_num_count;
        }
    
        return res;
    }
};
// @lc code=end

