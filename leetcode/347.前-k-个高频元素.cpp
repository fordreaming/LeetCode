// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem347.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    // 小顶堆
    class myComparision {
        public:
            bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs )
            {
                return lhs.second > rhs.second;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1、统计元素出现的次数
        std::unordered_map<int, int> unmap{};
        for (size_t i = 0; i < nums.size(); i++)
        {
            unmap[nums[i]]++;
        }
        
        // 2、构建元素的小顶堆， 按每个元素出现的次数进行排序
        // 优先级队列
        // priority_queue,大顶堆进行排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparision> pri_que{}; 

        // 固定大小为k的小顶堆
        for (unordered_map<int, int>::iterator it = unmap.begin(); it != unmap.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
         
        // 3、找出前k个高频元素
        vector<int> res(k, 0);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        
        return res;
    }
};
// @lc code=end

