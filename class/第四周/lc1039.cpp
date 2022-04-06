#include<bits/stdc++.h>
//22.3.14
/*
你有一个凸的 n 边形，其每个顶点都有一个整数值。给定一个整数数组 values ，其中 values[i] 是第 i 个顶点的值（即 顺时针顺序 ）。
假设将多边形 剖分 为 n - 2 个三角形。对于每个三角形，该三角形的值是顶点标记的乘积，三角剖分的分数是进行三角剖分后所有 n - 2 个三角形的值之和。
返回 多边形进行三角剖分后可以得到的最低分 。
*/
/*
又是区间dp问题
和戳气球 矩阵乘法链及其类似
但这个问题需要拜托数学知识的限制
*/
class Solution {                                                                                                                                                                                               
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
	    int **dp = new int*[n];
	for (int i = 0; i < n; i++)  dp[i] = new int[n]();//初始化全0
        for (int i = n-3; i >= 0; i--) {
            for (int j = i + 2; j < n;j++) {
                for (int m = i + 1; m < j; m++) {
                    if(dp[i][j]==0) 
                        dp[i][j]= A[i] * A[j] * A[m] + dp[i][m] + dp[m][j];
                    else 
                        dp[i][j] = min(dp[i][j],A[i] * A[j] * A[m] + dp[i][m] + dp[m][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};