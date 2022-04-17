#include<bits/stdc++.h>
//22.2.25
/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
*/
/*
这道题，有点无趣了，就是遍历一边，hash记录
但直接看题解才发现一个问题，它有很多字符出现一次，要返回第一个，hash就不能直接存频数，要存位置
不过也很简单  
用队列也很巧妙，
最后复刻一下队列解法
    反正效果不咋地
看哈希键值是否存在 count函数
*/
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> hash;
        queue<char> temp;
        for(int i=0;i<s.size();i++){
            if(!hash.count(s[i])){
                temp.push(s[i]);
                hash[s[i]]++;
            }
            else{
                hash[s[i]]++;
                while(temp.size()!=0&&hash[temp.front()]>1){
                    temp.pop();
                }
            }
        }
        if(!temp.size())return ' ';
        return temp.front();
    }
};