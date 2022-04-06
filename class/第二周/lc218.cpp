#include<bits/stdc++.h>
//22.3.2
/*
城市的 天际线 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回 由这些建筑物形成的 天际线 。
每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：
lefti 是第 i 座建筑物左边缘的 x 坐标。
righti 是第 i 座建筑物右边缘的 x 坐标。
heighti 是第 i 座建筑物的高度。
你可以假设所有的建筑都是完美的长方形，在高度为 0 的绝对平坦的表面上。
天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，
并按 x 坐标 进行 排序 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，
仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；
三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
*/
/*
天际线问题
很难，总是很难找到一个相对固定的准则去扫描这些建筑
看到题目标签有很多 树状数组 线段树 扫描线 这种灭见过的技巧 决定看题解 学习 

先是解法2 用了一个multiset 会自动排序（pair的自动排序是，先排first，first相等在排second） 把做左端点设成-  
遍历时会从左向右遍历  在重合位置 从高到低加左端点（没重复），再从低到高删右端点（没重复）
这种效果一般  时间复杂度是O(2*nlogn) 空间复杂度时O(2*n)

再看官方解法扫描线+优先队列（效果很好）
好像逐渐理解扫描线这个概念了
一条线从左往右扫描过这个图像，维护一个最大高度，发现变化说明改变 要存值
对于同一条线上的各点，会一次把所有高度导入，直接按照横坐标存进去，完美
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second < b.second; };
        //优先队列，只比较second
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        vector<int> boundaries;//把所有端点放入vector中
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());//从左到右排序
        vector<vector<int>> ret;//答案
        int n = buildings.size(), idx = 0;
        //只会记录左端点
        for (auto& boundary : boundaries) {//一次从左到右遍历端点
            while (idx < n && buildings[idx][0] <= boundary) {//idx是不变的，找到和当前便捷有关的所有建筑物信息
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!que.empty() && que.top().first <= boundary) {//删除已经过去的建筑物
                que.pop();
            }
            int maxn = que.empty() ? 0 : que.top().second;//看有没有高的建筑物
            if (ret.size() == 0 || maxn != ret.back()[1]) {//如果当前的高度不与前一个被添加的端点相同，就是答案
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};


// 一个比较简洁的思路，44ms，40%
// 把每栋房子看作矩形，首先把矩形(Li，-Hi)和(Ri，Hi)插入到multiset st中，自动排序
// 遍历multiset st，同时用另一个multiset height保存当前位置左边的历史高度，height.rbegin()即其最大值
// 遍历过程中，如果发现是Li，则插入到height，否则是Ri，删除Ri在height中对应的Li
// 如果height的最大值发生了变化，则该i元素就是返回结果之一
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        multiset<pair<int, int>> st;
        for (auto &b : buildings) {
            st.insert(make_pair(b[0], -b[2]));
            st.insert(make_pair(b[1], b[2]));
        }
        vector<vector<int>> ret;
        multiset<int> height{0};//这个0很关键，保证了所有空地都能被识别到
        int m = 0;
        for (auto& s : st) {
            if (s.second < 0) height.insert(-s.second); // 矩形左侧
            else height.erase(height.find(s.second)); // 矩形右侧
            if (m != *height.rbegin())
                ret.push_back({s.first, *height.rbegin()});
            m = *height.rbegin();
        }
        return ret;
    }
};
