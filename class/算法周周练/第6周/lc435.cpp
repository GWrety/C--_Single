#include<bits/stdc++.h>
//22.3.31
/*
给定一个区间的集合 intervals ，其中 intervals[i] = [start_i, end_i] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
*/
/*
已知贪心准则后用优先队列，最早结束的最先选
直接sort也许，但在练习优先队列，就用了优先队列，导致使用的空间比较大
这道题动态规划也能写  虽然c++会超时
dp【i】表示从0到i的能容纳区间个数最大值
内循环j遍历0-i然后max（dp【i】，dp【j】+1）
和最长上升子列lc300一致
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>>p;
        int n=intervals.size();
        for(int i=0;i<n;++i){
            p.push(make_pair(intervals[i][1],intervals[i][0]));
        }
        int leave=0;
        int pre=INT_MIN;
        while(!p.empty()){
            pair<int,int>temp =p.top();
            if(temp.second<=pre){
                leave++;
                pre=temp.first;
            }
            p.pop();
        }
        return n-leave;
    }
};