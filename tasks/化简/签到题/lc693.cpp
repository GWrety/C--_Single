#include<bits/stdc++.h>
//22.3.28
/*
给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
*/
//和1与 奇偶判断，左移
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int aim=n&1;
        while(n){
            if((n&1)==(aim%2)){
                n>>=1;
                aim++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
