#include<bits/stdc++.h>
//22.5.10
/*
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积 。
*/
/*
动态规划
从小到大拆，注意分析最后n的地方，因为k必须>=2；
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> maxmul(n+1,0);
        for(int i=0;i<n;++i) maxmul[i]=i;
        for(int i=0;i<=n;++i){
            int max=0;
            for(int j=1;j<=i/2;++j){
                max=std::max(max,maxmul[i-j]*maxmul[j]);
            }
            maxmul[i]=std::max(max,maxmul[i]);
        }
        return maxmul[n];
    }
};