// @before-stub-for-debug-begin
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1. 暴力法
        int n = gas.size();

        for (size_t i = 0; i < n; i++)
        {
            int rest = gas[i] - cost[i];       // 剩余油量
            int index = (i + 1)%n;

            while (rest > 0 && index != i)
            {
                /* code */
                rest += gas[index] - cost[index];
                index = (index + 1)%n;
            }

            if(rest >= 0 && index == i)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
