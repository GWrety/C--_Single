#include<bits/stdc++.h>
//22.3.28
/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/
/*
上课讲贪心时提过一嘴，说是无法用贪心准则
12=9+1+1+1
而其实：12=4+4+4最小
动态规划
一个数学定理可以帮助解决本题：「四平方和定理」。

四平方和定理证明了任意一个正整数都可以被表示为至多四个正整数的平方和。这给出了本题的答案的上界。
同时四平方和定理包含了一个更强的结论：当且仅当 n 不等于4^k *(8m+7) 时，n 可以被表示为至多三个正整数的平方和。
因此，当 n = 4^k * (8m+7) 时，nn 只能被表示为四个正整数的平方和。此时我们可以直接返回 4。
当 n 不等于4^k *(8m+7) 时，我们需要判断到底多少个完全平方数能够表示 nn，我们知道答案只会是 1,2,3中的一个：
答案为 1 时，则必有 n 为完全平方数，这很好判断；
答案为 2 时，则有 n=a^2+b^2
我们只需要枚举所有的a判断n-a^2是否为完全平方数即可；
答案为3时，我们很难在一个优秀的时间复杂度内解决它，但我们只需要检查答案为 1 或 2的两种情况，即可利用排除法确定答案。
*/
//dp
class Solution {
public:
    int numSquares(int n) {
        int* dp=new int[n+1];
        for(int i=1;i<=n;++i)dp[i]=INT_MAX;
        int temp=1;
        int tempD=1;
        while(tempD<=n){
            dp[tempD]=1;
            temp++;
            tempD=temp*temp;
        }
        for(int i=2;i<=n;++i){
            for(int j=1;j<temp;++j){
                if(i-j*j<1)break;
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
//数学
class Solution {
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }
    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }
    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};


