/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int first = 0;
        int second = 0;
        int max_dis = 0;

        bool is_first_one = true;
        int i = 0;
        while(n > 0) {
            if(n%2) {
                if(is_first_one) {
                    second = i;
                    first = i;
                    is_first_one = false;
                } else {
                    second = first;
                    first = i;
                }
                
                // std::cout << "first: " << first << "  second:  " << second << std::endl;
                if(first - second > max_dis) {
                    max_dis = first - second;
                }
            }
            // std::cout << "i  " << i << std::endl;
            // std::cout << "n   " << n << std::endl;
            n = n/2;
            i++;
        }

        return max_dis;
    }
};
// @lc code=end

