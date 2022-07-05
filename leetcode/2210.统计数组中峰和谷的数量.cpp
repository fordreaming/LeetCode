/*
 * @lc app=leetcode.cn id=2210 lang=cpp
 *
 * [2210] 统计数组中峰和谷的数量
 */

// @lc code=start
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // i [1, n-1)
        // to left and right and find not equal neighborhood elements
        //    if not find  return false;
        //    else : {
        //      copare, (nums[left] - nums[i])*(nums[right-nums[i]]) > 0
        //         return true;
        //          else :
        //          false;
        //    }
        if(nums.size() < 3) {
            return 0;
        }

        // remove repeat
        int res = 0;
        int n = nums_remove_repeat.size();

        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] != nums[i-1]) {
                int l = i - 1;
                int r = i + 1;

                while(l >= 0 && nums[l] == nums[i]) {
                    l--;
                }

                while(r < n && nums[r] == nums[i]) {
                    // std::cout << "r wile:::   " << r << std::endl;
                    r++;
                }

                // std::cout << "i:  " << i << std::endl;
                // std::cout << "l:  " << l << "   r:   " << r << std::endl;

                // compare
                if(l >= 0 && r < n) {
                    if((nums[l] - nums[i])*(nums[i] - nums[r]) < 0) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

