// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 贪心算法，局部最优可以推出全局最优
        
        // 小饼干优先满足小胃口

        // 1、胃口升序
        sort(g.begin(), g.end());

        // 2、尺寸升序
        sort(s.begin(), s.end());

        // 3、遍历饼干
        int res = 0;
        size_t i = 0;
        size_t j = 0;

        while (i < s.size() && j < g.size())        
        {
            if (s[i] < g[j])
            {
                i++;
            }
            else
            {
                res++;
                i++;
                j++;
            }    
        }

        return res;
    }
};
// @lc code=end

