#include<bits/stdc++.h>
//22.4.5
/*
给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。
计算置位位数 就是二进制表示中 1 的个数。
例如， 21 的二进制表示 10101 有 3 个计算置位。
*/
/*
简单题卡的不严 倒是可以不断优化
*/
//朴素判断法
class Solution {
private:
    int x;
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(;left<=right;++left){
            int wit=__builtin_popcount(left);
            x=wit;
            ans+=isprime()==1?1:0;
        }
        return ans;
    }
    bool isprime(){
        if(x==2) return true;
        if(x%2==0 || x<2)return false;
        else{
		for(int i=3;i*i<=x;i+=2){
			if(x%i==0){
				return false;
			}
		}
        }
		return true;
    }
};
//Robbin算法
class Solution {
private:
    int x;
public:
    int countPrimeSetBits(int left, int right) {
        srand(time(0));
        int ans=0;
        for(;left<=right;++left){
            int temp=left;
            int wit=0;
            while(temp){
                if(temp&1) wit++;
                temp>>=1;
            }
            x=wit;
            ans+=query_prime()==1?1:0;
        }
        return ans;
    }
int qpow(int a,int b,int mod){//快速幂
    int res=1;
    while(b){
        if(b&1) res=(res%mod*a)%mod;
        a=(a%mod)*a%mod;
        b>>=1;
    }
    return res;
}
bool query_prime(){
    if(x==2)return true;
    if(x==1)return false;
    for(int i=1;i<=30;i++){
        int base=rand()%(x-1)+1;//随机枚举a
        if(qpow(base,x-1,x)!=1) return false;//计算a^(p-1)%p的值
    }
    return true;
}
};
//基于题目数据最简单的写法
//int最多32个1，再加上right限制，最大19
//我们可以用一个二进制数mask=665772=10100010100010101100 
//来存储这些质数，其中 mask 二进制的从低到高的第 ii 位为 11 表示 ii 是质数，为 00 表示 ii 不是质数。
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};