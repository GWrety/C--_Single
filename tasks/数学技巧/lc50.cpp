#include<bits/stdc++.h>
//22.2.23
//快速幂的解法
//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn ）。
/*
本质上快速幂就是用二进制拆开，发现每一项可以递推得到，减少了计算步骤。
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        return n>0? function(x,abs(n)):1/function(x,abs(1));
    }
    double function(double x,int n){
        double answer=1;
        double temp=x;
        while(n>0){
            if(n&1){
                answer*=temp;
            }
            n>>=1;
            temp*=temp;
        }
        return answer;
    }
};