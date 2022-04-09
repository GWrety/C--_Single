#include<bits/stdc++.h>
//22.4.9
/*
从正向去思考是一道深度搜索问题，由于状态很多，成指数级上升，很难求解正确
由推断结果反向推导过程
大的数一定是有小的数加一个值的来的  可以回退回状态 直接去模 避免重复计算
反向思路如果get到确实简单
但这个反向思路确实很难
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy) {
            return true;
        } else if (tx == sx) {
            return ty > sy && (ty - sy) % tx == 0;
        } else if (ty == sy) {
            return tx > sx && (tx - sx) % ty == 0;
        } else {
            return false;
        }
    }
};
