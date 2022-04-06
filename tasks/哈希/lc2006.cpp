#include<bits/stdc++.h>
//22.2.9
/*
    给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。
*/
//这道题思路比较好,
//明确知道要统计的是什么，用哈希表很简单

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        if(k<0)return 0;
        int answer=0;
        int s_map[101];
        memset(s_map,0,sizeof(s_map));
        for(int i=0;i<nums.size();i++){
            answer+=s_map[nums[i]];
            if(nums[i]+k<=100){
                s_map[nums[i]+k]++;
            }
            if(nums[i]-k>=0){
                s_map[nums[i]-k]++;
            }
        }
        return answer;
    }
};