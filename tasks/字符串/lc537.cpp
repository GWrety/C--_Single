#include<bits/stdc++.h>
//22.2.25
/*
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100,100]
虚部 也是一个整数，取值范围是 [-100，100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。
*/
/*
    shit 被网上很多所谓的stoi函数的解释骗了，那个起始位置根本没有用
    string似乎没有分割函数，，转成char[]才能解决
*/
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1,b1,a2,b2; 
        for(int i=0;i<num1.size();i++){
            if(num1[i]=='+'){
                char * d=&num1[i+1];
                a1=stoi(num1);
                b1=atoi(d);
                break;
            }
        }
        for(int i=0;i<num2.size();i++){
            if(num2[i]=='+'){
                char * d=&num2[i+1];
                a2=stoi(num2);
                b2=atoi(d);
                break;
            }
        }
        int c=a1*a2-b1*b2;
        int d=a1*b2+a2*b1;
        string ans;
        string c1=to_string(c);
        string d1=to_string(d);
        ans+=c1;
        ans.push_back('+');
        ans+=d1;
        ans.push_back('i');
        return ans;
    }
};