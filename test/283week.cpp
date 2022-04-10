#include<bits/stdc++.h>
//22.3.6 1/4
class Solution {
public:
    vector<string> cellsInRange(string s) {
        char start=s[0];
        char a=s[1];
        char end=s[3];
        char b=s[4];
        vector<string> ans;
        while(start<=end){
            string temp="";
            temp+=start;
            for(char i=a;i<=b;++i){
                temp+=i;
                ans.push_back(temp);
                temp.pop_back();
            }
            ++start;
        }
        return ans;
    }
};
//超时？？？ 不一个一个加还能咋加
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int wit=1;
        int i=0;
        while(i<nums.size()&&k>0){
            while(k>0&&i<nums.size()&&nums[i]>wit){
                ans+=wit;
                ++wit;
                --k;
            }
            wit=nums[i]+1;
            ++i;
        }
        if(k!=0){
            while(k!=0){
                ans+=wit;
                ++wit;
                --k;
            }
        }
        return ans;
    }
};
//第二题解法 贪心  主要利用高斯定理简化运算  要不然过不了  效果很好
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // 排序为了去重 也方面k后移
        sort(nums.begin(), nums.end());
        int n = unique(nums.begin(), nums.end()) - nums.begin(); // 所谓的去重只是把多余的数移到了最后面并没有删除
        long long d = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= k)
            {
                d += nums[i];
                ++k;
            }
        }
        return (1LL + k) * k / 2 - d;
    }
};














