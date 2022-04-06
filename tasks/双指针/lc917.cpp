#include<bits/stdc++.h>
//22.2.23
/*
给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。
*/
/*
    把所有需要转换的下标存到vector里，前后转换即可
        结果：时间很短，但内存消耗很大
    看题解;
        .....双指针 更好，时间更短，空间更小....
*/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<int> waiting;
        for(int i=0;i<s.size();i++){
            if(s[i]<='Z'&&s[i]>='A'||s[i]<='z'&&s[i]>='a'){
                waiting.push_back(i);
            }
        }
        for(int i=0;i<waiting.size()/2;i++){
            char temp=s[waiting[i]];
            s[waiting[i]]=s[waiting[waiting.size()-i-1]];
            s[waiting[waiting.size()-i-1]]=temp;
        }
        return s;
    }
};