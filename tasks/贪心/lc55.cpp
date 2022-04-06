#include<bits/stdc++.h>
//22.2.26
/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/
/*
额......虽然是动态规划计划里的题，but我用逆序的方式，试探发现也求解出来了...
额......确实不是动态规划，同贪心准则更快,....属于是多次一举了...
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int aim=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=aim){
                aim=0;
            }
            aim++;
        }
        return aim==1;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
};