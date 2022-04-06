#include<bits/stdc++.h>
//22.2.14
/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
请你找出并返回只出现一次的那个数。
你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
*/
//另类的二分，根据时间复杂度马上识别

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int left=0;
        int right=nums.size()-1;
        int temp;
        while(left<right){
            temp=(left+right)/2;
            if(nums[temp+1]==nums[temp]){
                if((right-temp+1)%2){
                    left=temp+2;
                }
                else{                 
                    right=temp-1;
                }
            }
            else if(nums[temp-1]==nums[temp]){
                if((right-temp)%2){
                    left=temp+1;
                    
                }
                else{
                    right=temp-2;
                }
            }
            else{
                return nums[temp];
            }
        }
        return nums[left];
    }
};