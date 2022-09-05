#include<bits/stdc++.h>
//22.3.7
/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
*/
/*
递归解法
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return function(nums,0,nums.size()-1);
    }
    int function(vector<int>& nums,int left,int right){
        if(right-left==0) return nums[left];
        int mid=left+(right-left)/2;
        int maxleft=function(nums,left,mid);
        int maxright=function(nums,mid+1,right);
        int maxmidleft=INT_MIN;
        int maxmidright=INT_MIN;
        int temp=0;
        for(int i=mid;i>=left;i--){
            temp+=nums[i];
            maxmidleft=max(maxmidleft,temp);
        }
        temp=0;
        for(int i=mid+1;i<=right;i++){
            temp+=nums[i];
            maxmidright=max(maxmidright,temp);
        }
        int maxmid=maxmidleft+maxmidright;
        int maxfinal=max(maxmid,maxleft);
        maxfinal=max(maxfinal,maxright);
        return maxfinal;
    }
};