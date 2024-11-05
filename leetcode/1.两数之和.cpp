// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"
#include <unordered_map>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res{};
        std::unordered_map<int, int>  unmap{};

        for (size_t i = 0; i < nums.size(); i++)
        {
            // 找到就加入下标
            if (unmap.find(nums[i]) != unmap.end())
            {
                // res = {i, ummap[nums[i]]};
                res.push_back(i);
                res.push_back(unmap[nums[i]]);
                break;
            }
            else
            {
                unmap[target - nums[i]] = i;
            } 
        }
        
        return res;
    }
};
// @lc code=end

