#include<bits/stdc++.h>
//22.4.22
/*
暴力穷举也行 时间复杂度也是n2  超时
错位相减  没想到gg
需要考虑每次循环的关系  在dp矩阵中上一行和下一行的关系就是
dp[n]=dp[n-1]-sum(data) +n*data[n]
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=INT_MIN;
        for(int i=0;i<n;++i){
            int temp=0;
            for(int k=0;k<n;++k){
                temp+=k*nums[(i+k)%n];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=0;
        for(int k=0;k<n;++k){
            ans+=k*nums[k];
        }
        int Sum=accumulate(nums.begin(),nums.end(),0);
        int temp=ans;
        for(int i=1;i<n;++i){
            temp-=Sum;
            temp+=n*nums[i-1];
            ans=max(ans,temp);
        }
        return ans;
    }
};