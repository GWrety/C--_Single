#include<bits/stdc++.h>
//22..2.24
/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。
*/
/*
    这道题其实和lc70一样了，就是把转移方程做个选择，从亮项中间选一个即可
    大致就这种解法了，矩阵没法用
    其实也有不同，这种和斐波那契那种动态规划就不同了！！！
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2)return cost[0]>cost[1]?cost[1]:cost[0];
        int p=0,q=0,r=0;
        for(int i=2;i<=n;i++){
            p=q;
            q=r;
            r= (p+cost[i-2])>(q+cost[i-1])? q+cost[i-1]:p+cost[i-2];
        }
        return r;
    }
};