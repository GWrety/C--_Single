#include<bits/stdc++.h>
//22.4.4
/*
bool数组判断是否可以组成 判断vector简化判断过程
先把所有bool测满 再从小添加  小的收益最大的
这么做是正确的，但效率太差了，相当于暴力最优化的结果 

这道题感觉和贪心关系不大，倒是和技巧有很大关系，前提是数组内的数字不能重复使用，有两个要点
首先：（1，x-1）全覆盖，且x在数组内，则（1，2*x-1）也全覆盖，由x加上小的那一半得证
然后：对于（1，x-1）中的内容，来一个没有用过的小于x的数t，整个范围会向左端延展t（这个比较难想到）
*/
//暴力error
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<int> IsFull((long long)n+1,0);
        //先把初始组合检查
        for(auto &x:nums){
            if(x<=n){
                for(long long i=1;i<=n;++i){
                    if(IsFull[i]==1){
                        if(i+x<=n){
                            IsFull[i+x]=1;
                        }
                    }
                    else if(i==x){
                        IsFull[i]=1;
                    }
                }
            }
        }
        queue<int> wait;//不满足数
        for(int i=1;i<=n;++i){
            if(!IsFull[i]){
                wait.push(i);
            }
        }
        int ans=0;
        while(!wait.empty()){
            int temp=wait.front();
            wait.pop();
            ans++;
            for(long long i=1;i<=n;++i){
                    if(IsFull[i]==1){
                        if(i+temp<=n){
                            IsFull[i+temp]=1;
                        }
                    }
                    else if(i==temp){
                        IsFull[i]=1;
                    }
            }
            queue<int> x;
            while(!wait.empty()){
                int t=wait.front();
                wait.pop();
                if(!IsFull[t]){
                    x.push(t);
                }
            }
            wait=x;
        }
        return  ans;
    }
};
//题解
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;//x-1的数全覆盖
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];//全区间都可以加这个数 整段全覆盖
                index++;
            } 
            else {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};