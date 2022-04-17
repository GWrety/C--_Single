#include<bits/stdc++.h>
//22.3.24
/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/
/*
很难，没思路
看懂题解后还挺简单的
对于这种二维抽象题目，比较薄弱。
*/
//单调栈 朴素 先建栈，再遍历
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {//单调 只要小的
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());//存值
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {//左右夹逼得到宽度
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
//一遍栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        int n=heights.size();
        stack<int> S_stack;
        S_stack.push(0);
        int ans=0;
        for(int i=1;i<n;++i){
            while(heights[i]<heights[S_stack.top()]){//高度下降
                int temp=S_stack.top();
                S_stack.pop();
                ans=max(ans,(i-S_stack.top()-1)*heights[temp]);
            }
            S_stack.push(i);
        }
        return ans;
    }
};


