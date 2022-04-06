#include<bits/stdc++.h>
//22.3.25
/*
给定一个整数 n ，返回 n! 结果中尾随零的数量。
提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
*/
/*
可通过求解阶乘去获得0
想想有没有其他直接的到0的办法
和5相乘偶数为+0。乘10+0
要求对数时间
嘴和思路就是和5有关，多5多一个
接近双百    
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0,temp=5;
        while(temp<=n){ans+=n/temp;temp*=5;}
        return ans;
    }
};
