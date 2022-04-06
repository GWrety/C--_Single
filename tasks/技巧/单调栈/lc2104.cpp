#include<bits/stdc++.h>
//22.3.4
/*
给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。
返回 nums 中 所有 子数组范围的 和 。
子数组是数组中一个连续 非空 的元素序列。
*/
/*
最质朴的暴力解法n3过不了
看题解换一种 n2以每个数组为起始点的子数组
单调栈的解法 直接找答案的组成 元组max- 元组min
需要找到每个元素在其中贡献了多少
效果确实很好
*/
//纯暴力n3
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();    
        if(nums.size()==1)return 0;
        int gap=2;
        long long ans=0;
        while(gap<=n){
            int left=0,right=gap+left-1;
            for(;right<=n-1;++left,++right){
                int min=INT_MAX,max=INT_MIN;
                for(int i=left;i<=right;++i){
                    if(nums[i]>max)max=nums[i];
                    if(nums[i]<min)min=nums[i];
                }
                ans+=max-min;
            }
            ++gap;
        }
        return ans;
    }
};
//稍微优化n2
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();    
        if(nums.size()==1)return 0;
        long long ans=0;
        for(int i=0;i<nums.size();++i){
            int minN=nums[i];
            int maxN=nums[i];
            for(int j=i+1;j<n;j++){
                maxN=max(maxN,nums[j]);
                minN=min(minN,nums[j]);
                ans+=maxN-minN;
            }
        }
        return ans;
    }
};
//单调栈
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> minStack, maxStack;
        for (int i = 0; i < n; i++) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);
            
            // 如果 nums[maxStack.top()] == nums[i], 那么根据定义，
            // nums[maxStack.top()] 逻辑上小于 nums[i]，因为 maxStack.top() < i
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) { 
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        minStack = stack<int>();
        maxStack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            // 如果 nums[minStack.top()] == nums[i], 那么根据定义，
            // nums[minStack.top()] 逻辑上大于 nums[i]，因为 minStack.top() > i
            while (!minStack.empty() && nums[minStack.top()] >= nums[i]) { 
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }

        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < n; i++) {
            sumMax += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
            sumMin += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
        }
        return sumMax - sumMin;
    }
};