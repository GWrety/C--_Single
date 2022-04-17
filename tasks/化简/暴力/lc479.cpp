#include<bits/stdc++.h>
//求解在两个整数都是n位时，相乘起来是一个回文数字  要求此回文数字最大，返回模1337的值
/*
暴力穷举所有回文数，看能不能吧他拆成两个n位数的乘积
*/
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; --left) { // 枚举回文数的左半部分
            long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10; // 翻转左半部分到其自身末尾，构造回文数 p
            }
            for (long x = upper; x * x >= p; --x) {
                if (p % x == 0) { // x 是 p 的因子
                    return p % 1337;
                }
            }
        }
    }
};