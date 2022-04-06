#include<bits/stdc++.h>
///22.2.23
/*
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*/
/*
    动态规划第一题，以为一个备忘录数组就行了，
    看题解：
        这样做内存消耗很大
    优化：
        可以只维护一个大小为4的数组；
    其实可以直接打表，很快，因为题目说了0<=n<=37,直接建一个38数组存好return秒杀
    在看题解 （原来的时间复杂度是o（n），为了优化时间）发现了用线性代数的知识求解，
        得到矩阵的方程，通过求矩阵快速幂的方法，把时间压缩为long（n）
*/
//压缩空间后的动态规划
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        int p = 0, q = 0, r = 1, s = 1;
        for (int i = 3; i <= n; ++i) {
            p = q;
            q = r;
            r = s;
            s = p + q + r;
        }
        return s;
    }
};

//矩阵快速幂解法
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        vector<vector<long>> q = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        vector<vector<long>> res = pow(q, n);
        return res[2][0]+res[2][1];//return res[0][2]  也对 就是把起始公式变形了一下
    }
    vector<vector<long>> pow(vector<vector<long>>& a, long n) {
        vector<vector<long>> ret = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }
    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> c(3, vector<long>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
            }
        }
        return c;
    }
};
