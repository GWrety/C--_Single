#include<bits/stdc++.h>
//22.3.7
/*
把一个int转边为7进制的数
*/
/*
用栈确实快
但会消耗过多的空间
可以改用原地翻转  这样空间消耗会少一点
*/
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if(num==0) return "0";
        int temp=num;
        if(num<0)num=0-num;
        while(num!=0){
            int t=num%7;
            num/=7;
            ans.push_back(t+'0');
        }
        if(temp<0){
            ans.push_back('-');
        }
        temp=ans.size();
        for(int i=0;i<temp/2;++i){
            char t=ans[i];
            ans[i]=ans[temp-1-i];
            ans[temp-1-i]=t;
        }
        return ans;
    }
};