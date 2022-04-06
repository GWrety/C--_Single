#include<bits/stdc++.h>
//22.3.31
/*
给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
*/
//滑动窗口
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,ans=0;
        for(int left=0,right=0;right<n;++right){
            sum+=nums[right]==0;
            if(sum>k){
                while(nums[left]!=0){
                    left++;
                }
                sum-=nums[left]==0;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
//二分查找
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> P(n + 1);//前缀和
        for (int i = 1; i <= n; ++i) {
            P[i] = P[i - 1] + (1 - nums[i - 1]);
        }
        int ans = 0;
        for (int right = 0; right < n; ++right) {
            int left = lower_bound(P.begin(), P.end(), P[right + 1] - k) - P.begin();
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};