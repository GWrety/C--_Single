#include<bits/stdc++.h>
//22.2.26
/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，
这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
*/
/*
这道题就是lc198的变式，算是要对它做一些补充修正
看题解：就是把这题分成俩子类做，排除第一和最后一间都偷的情况
    如果这两种情况的最大值还存在，那一定是把两间屋都偷了，要不然就包含在俩者之一了
    很难
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        else if(nums.size()==2) return nums[0]>nums[1]?nums[0]:nums[1];

        int p=0,q=nums[0],r=nums[1]>nums[0]?nums[1]:nums[0];
        for(int i=2;i<nums.size()-1;i++){
            p=q;
            q=r;
            r=(p+nums[i])>q? p+nums[i]:q;
        }

        int p2=0,q2=nums[1],r2=nums[1]>nums[2]?nums[1]:nums[2];
        for(int i=3;i<nums.size();i++){
            p2=q2;
            q2=r2;
            r2=(p2+nums[i])>q2? p2+nums[i]:q2;
        }


        return r>r2?r:r2;
    }
};