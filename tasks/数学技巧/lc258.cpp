#include<bits/stdc++.h>
//22.3.2
/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
*/
/*
暴力解法， 一遍AC
简单题背后必然有深奥的数学解法，
是求一个数的数根：
num 不是 9 的倍数时，其数根即为num 除以 9 的余数。
num 是 9 的倍数时：
如果num=0，则其数根是 0；
如果num>0，则各位相加的结果大于 0，其数根也大于 0，因此其数根是 9。
那个返回也很巧妙 排除了0 解决了%9=0的情况   牛！！！
*/
//暴力
class Solution {
public:
    int addDigits(int num) {
        string temp=to_string(num);
        while(temp.size()>1){
            int a=0;
            for(int i=0;i<temp.size();++i){
                a+=temp[i]-'0';
            }
            temp=to_string(a);
        }
        return stoi(temp);
    }
};
//数学秒杀
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};