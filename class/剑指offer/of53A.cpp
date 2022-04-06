#include<bits/stdc++.h>
//22.2.24
/*
统计一个数字在排序数组中出现的次数。
*/
/*
    二分找位置,就是求重复数组的始末位置
    对二分中mid跳转要敏感，注意=时的执行条件。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return 0;
        else if(target>nums[nums.size()-1]||target<nums[0]) return 0;
        int leftmin=0,rightmin=nums.size()-1;
        int leftmax=0,rightmax=nums.size()-1;
        while(leftmin<=rightmin){
            int midmin=(leftmin+rightmin)/2;
            if(nums[midmin]<target){
                leftmin=midmin+1;
            }
            else{
                rightmin=midmin-1;
            }
        }
        if(nums[leftmin]!=target)return 0;
        while(leftmax<=rightmax){
            int midmax=(leftmax+rightmax)/2;
            if(nums[midmax]<=target){
                leftmax=midmax+1;
            }
            else{
                rightmax=midmax-1;
            }
        }
        return leftmax-leftmin;
    }
};