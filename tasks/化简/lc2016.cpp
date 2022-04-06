#include<bits/stdc++.h>
//22.2.26
/*
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，
其中 0 <= i < j < n 且 nums[i] < nums[j] 。
返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。
*/
/*
    首先数据无序，最猪鼻解法就是n（n+1）
    优化：
        首先这种题，排序也行，但是意义不大
        没想到了
    看题解：
        一次遍历竟然也行！！！
        其实和求栈min那道（of30）题思路一样，维护一个最小的！
        一遍ac，这种题思路都比较奇特，维护一个最小值就可以了
*/
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        if(nums.size()<=1)return -1;
        int min=nums[0];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans>(nums[i]-min)? ans:nums[i]-min;
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return ans>0? ans:-1;
    }
};