#include<bits/stdc++.h>
//22.2.24
/*
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
*/
/*
    最直接的就是hash_map直接扫一遍，有重复的输出即可，O（n），O（n）
    想了一下。先排序感觉优化效率不是很大。没啥用，看题解
    有更优化的方法，原地哈希，O(n),O(1); 
    很妙，节省空间，没见过的思路！！！
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};