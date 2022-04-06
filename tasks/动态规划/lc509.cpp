#include<bits/stdc++.h>
//22.2.23
/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。

*/
/*
就是leetcode1137简化版，一种压缩空间动态规划，一种矩阵快速幂
*/
//动态规划
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1) return 1;
        int p=0,q=0,r=1;
        for(int i=2;i<=n;i++){
            p=q;
            q=r;
            r=p+q;
        }
        return r;
    }
};
//矩阵快速幂
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1) return 1;
        vector<vector<long>> M={{1,1},{1,0}};
        vector<vector<long>> ans=pow(M,n);
        return ans[1][0];
    }
    vector<vector<long>> pow(vector<vector<long>>& a,int n){
        vector<vector<long>> res ={{1,0},{0,1}};
        while(n>0){
            if(n&1){
                res =mul(res,a);
            }
            a=mul(a,a);
            n>>=1;
        }
        return res;
    }
    vector<vector<long>> mul(vector<vector<long>>& a,vector<vector<long>>& b){
        vector<vector<long>> c(2,vector<long>(2));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
            }
        }
        return c;
    }

};
