#include<bits/stdc++.h>
//22.3.1
/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
*/
/*
找规律，简单题目
*/
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if(numRows==1) return s;
        for(int i=1;i<=numRows;i++){
            int p=numRows-i;
            if(i==1||i==numRows){
                p=numRows-1;
            }
            int now=i+0*p;
            while(now<=s.size()){
                ans.push_back(s[now-1]);
                now+=2*p;
                if(i!=1&&i!=numRows){
                    p=numRows-1-p;
                }

            }
        }
        return ans;
    }
};