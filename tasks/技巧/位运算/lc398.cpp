#include<bits/stdc++.h>
//22.3.13
/*
给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。
UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，
后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
*/
/*
应该就是扫一遍 标记状态不符合扔掉吧
看题解发现  其实根据元素大小卡范围就行了，和网络中ipv4寻址一样
*/
class Solution {
public:
    bool validUtf8(vector<int>& data){
        int aim=0;
        for(auto num:data){
            if(!(num&(1<<7))&&!aim) continue;
            else if(!(num&(3<<6)^(1<<7))&&aim)--aim;
            else if(!(num&(7<<5)^(3<<6))&&!aim)aim=1;
            else if(!(num&(15<<4)^(7<<5))&&!aim)aim=2;
            else if(!(num&(31<<3)^(15<<4))&&!aim)aim=3;
            else return false;
        }
        if(!aim)return true;
        return false;
    }
};