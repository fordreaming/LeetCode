// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem121.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // 1、一次遍历，记录最小值，此时知道买卖操作的索引，待会实现一下
    // 2、贪心解法： 最大利润： max_profit = prices[h] - prices[l]   // h表示最高价格的索引、l表示最低价格的索引
    //                                = sigma(prices[i] - prices[i-1])
    // 为了利润最大化，我们只记录利润>=0的值
    // 3、动态规划
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        vector<int> sell_idxs{};

        int min_price = INT_MAX;
        int min_price_idx = 0;

        for (size_t i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
                min_price_idx = i;
            }
            else if (prices[i] - min_price > max_profit)
            {
                max_profit = prices[i] - min_price;
                max_profit_idx = i;
            }
            else
            {
                // nothing to do
            }
        }
        
        std::cout << "min_price: " << min_price << "  min_price_idx: " << min_price_idx
                    << " max_profit: " << max_profit << " max_profit_idx: " << max_profit_idx
                    << std::endl;

        return max_profit;
    }
};
// @lc code=end

