#include<bits/stdc++.h>
//22.2.26
/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
*/
/*
感觉我这种所发算暴力解法，能过，但效果很差
看了题解，发现其实可以优化........shit
感觉被动态规划搞乱了，这道题和lc55其实就是常规问题，去想它的过程就是可以化简做的
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int* dp=new int [n];
        for(int i=0;i<n;i++){
            dp[i]=INT_MAX;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i];j++){
                if(i+j<n){
                    if(dp[i+j]<dp[i]+1){
                        dp[i+j]=dp[i]+1;
                    }
                }
                else{
                    break;
                }
            }
        }
        return dp[n-1];
    }
};
//优化解法
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), 
        end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};