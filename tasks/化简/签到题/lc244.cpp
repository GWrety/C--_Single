#include<bits/stdc++.h>
//22.3.15
/*
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。
如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，
则认为两个子集 不同 。
对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

*/
/*
签到提深搜枚举
*/
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        int times=0;
        function(nums,0,ans,times,0);
        return times;
    }
    void function(vector<int>& nums,int now,int& ans,int& times,int tmp){
        if(nums.size()==now) {
            if(tmp>ans){
            ans=tmp;
            times=1;
            }
            else if(tmp==ans){
                times++;
            }
            return;
        }
        function(nums,now+1,ans,times,tmp|nums[now]);
        function(nums,now+1,ans,times,tmp);
    }
};