#include<bits/stdc++.h>
//22.5.10
/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/
/*
背包问题， 容量为整数和的一半
看最后的背包是不是满的 
但效率不是很高
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return 0;
        vector<vector<int>> wit(n+1,vector<int>(sum/2+1,0));
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=sum/2;++j){
                if(nums[i-1]<=j)
                    wit[i][j]=max(wit[i-1][j],wit[i-1][j-nums[i]]+nums[i-1]);
                else
                    wit[i][j]=wit[i-1][j];
            }
        }
        return wit[n][sum/2]==sum/2? 1:0;
    }
};