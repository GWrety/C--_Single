#include<bits/stdc++.h>
//22.3.5
/*
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。
必须 原地 修改，只允许使用额外常数空间。
*/
/*
必须原地修改，不允许使用额外空间
总之就是找到规律，
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        for(int i=0;i<nums.size();){ 
            //去找它后面没有其他数字排序可能的情况
            int j=i+1;
            if(j<nums.size()){
                int pre=nums[j];
                ++j;
                while(j<nums.size()){
                    if(nums[j]<=pre){
                        pre=nums[j];
                        ++j;
                    }
                    else{
                        --j;
                        break;
                    }
                }
            }
            if(j==nums.size()){//此时i后没有其他选择 需要调大的上来
                if(i==0&&nums[0]>nums[1]){//开头就是最大，而且全部逆序
                    //执行逆转操作
                    for(int k=0;k<nums.size()/2;++k){
                        int temp=nums[k];
                        nums[k]=nums[nums.size()-1-k];
                        nums[nums.size()-1-k]=temp;
                    }
                    return ;
                }
                int tag=0;
                for(int k=j-1;k>i;--k){//把离k最近大的一位交换上来
                    if(nums[k]>nums[i]){
                        if(!tag){
                            tag=k;
                        }
                        if(nums[k]<nums[tag]){
                            tag=k;
                        }
                    }
                }
                int temp=nums[tag];
                nums[tag]=nums[i];
                nums[i]=temp;
                for(int k=0;k<(j-i-1)/2;++k){//交换剩下的
                    int temp=nums[i+1+k];
                    nums[i+1+k]=nums[j-1-k];
                    nums[j-1-k]=temp;
                }
                return;
            }       
            else{
                i=j;
            }
        }
    }
};


