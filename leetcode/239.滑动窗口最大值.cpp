// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <deque>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

class Solution {
    class MyQueue
    {
    public:
        void pop(int val)
        {
            if (!m_deque.empty() && val == m_deque.front())
            {
                m_deque.pop_front();
            }
            
        }

        void push(int val)
        {
            while (!m_deque.empty() && val > m_deque.back())
            {
                m_deque.pop_back();
            }

            m_deque.push_back(val);
            
        }

        int front()
        {
            return m_deque.front();
        }

    private:
        std::deque<int>  m_deque{};
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res{};
        MyQueue myQueue{};

        for (size_t i = 0; i < k; i++)
        {
            myQueue.push(nums[i]);    
        }

        // 前3个元素中，需要获取一个最大值
        res.push_back(myQueue.front());
        
        for (size_t i = k; i < nums.size(); i++)
        {
            myQueue.pop(nums[i-k]);
            myQueue.push(nums[i]);
            

            res.push_back(myQueue.front());
        }

        return res;
        
    }
};
// @lc code=end

