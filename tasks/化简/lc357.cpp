#include<bits/stdc++.h>
//22.4.11
/*
给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。
传统排列组合问题，  没意思了
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int ans = 10, cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur *= 9 - i;
            ans += cur;
        }
        return ans;
    }
};
//我直接打表  啪  很快啊
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        switch(n){
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 100-9;
        case 3:
            return 739;
        case 4:
            return 5275;
        case 5:
            return 32491;
        case 6:
            return 168571;
        case 7:
            return 712891;
        default:
            return 2345851;
        } 
    }
};