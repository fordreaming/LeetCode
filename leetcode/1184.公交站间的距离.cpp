/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int total = std::accumulate(distance.begin(), distance.end(), 0);
        int dis = 0;
        for(int i = start; i != destination; i = (i + 1)%n) {
            dis += distance[i];
        }

        return std::min(dis, total - dis);
    }
};
// @lc code=end

