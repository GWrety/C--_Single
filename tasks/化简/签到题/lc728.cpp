#include<bits/stdc++.h>
//22.3.31
/*
自除数 是指可以被它包含的每一位数整除的数。
例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
自除数 不允许包含 0 。
给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。
*/
/*
签到题，简单。
*/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(;left<=right;left++){
            int temp=left;
            int aim=temp%10;
            while(temp){
                if(aim==0||(left/aim)*aim!=left) break;
                else{
                    temp/=10;
                    aim=temp%10;
                }
            }
            if(temp==0) ans.push_back(left);
        }
        return ans;
    }
};