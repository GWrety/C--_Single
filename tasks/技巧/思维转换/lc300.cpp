#include<bits/stdc++.h>
//22.3.31
/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/
/*
课上要求的经典动态规划问题
但动态规划时间复杂度是O（n^2）
看题解发现有一种nlogn解法  太妙了吧
*/
//n^2的dp解法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[j]+1,dp[i]);
                    ans=max(dp[i],ans);
                }
            }
        }
        return ans;
    }
};
//nlogn解法  贪心+二分
//还可以靠一个返回最长序列，本质上来一个vector<vector>来存就行了 更新一个就是vector<前一个>push这个元素
//不能直接返回d数组，前后顺序杂交，
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {//相当于构造了一个有序列表，可以使用二分法查找来优化时间
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } 
            else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];//一个新员工一个老员工价值相当，老员工就可以走了，因为新员工被榨取的剩余空间更多
            }
        }
        return len;
    }
};