#include<bits/stdc++.h>
//22.2.24
/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
*/
/*
    继续二分，解决
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>mid){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};