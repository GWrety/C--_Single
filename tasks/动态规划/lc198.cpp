#include<bits/stdc++.h>
//22.2.26
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/
/*
如果已知是动态规划问题，感觉就和爬楼梯（耗费最少的体力）是一样的
保留有 截至到n家能偷的最多的钱
偷第n家最多的前只与前n-1家最多的钱和前n-2家最多的钱有关
得到状态转移方程 
这个思路有点绕，动态规划确实不好想啊
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        else if(nums.size()==2) return nums[0]>nums[1]?nums[0]:nums[1];
        int p=0,q=nums[0],r=nums[1]>nums[0]?nums[1]:nums[0];
        for(int i=2;i<nums.size();i++){
            p=q;
            q=r;
            r=(p+nums[i])>q? p+nums[i]:q;
        }
        return r;
    }
};