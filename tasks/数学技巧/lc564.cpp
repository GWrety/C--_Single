#include<bits/stdc++.h>
//22.3.2
/*
给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。
“最近的”定义为两个整数差的绝对值最小。
*/
/*
第一想法就是翻转小的一半，但要识别三种在边界的情况，和已经是回文的情况
对于之后的部分，要注意是否是最近的，对于大的要找一个小的比较，反之亦然
时间复杂度 O（n）
空间复杂度很大O（n）
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size()==1) return to_string(atoi(&n[0])-1);//识别10以下
        int size=n.size();
        //识别10 100 边界
        long temp=stol(n);
        --temp;
        string a=to_string(temp);
        if(a.size()<size)return a;
        //识别11，101 1001 10001边界
        --temp;
        a=to_string(temp);
        if(a.size()<size)return a;
        //识别99 999 9999边界
        temp+=4;
        a=to_string(temp);
        if(a.size()>size) {
        return a;
        }
        
        //识别是否已经是回文
        int lag=0;
        for(int i=size/2;i<size;i++){
            if(size%2){
                if(n[i]!=n[size/2+(size/2-i)]){
                    lag=1;
                    break;
                }
            }
            else{
                if(n[i]!=n[size/2-1+(size/2-i)]){
                    lag=1;
                    break;
                }
            }
        }
        if(lag){
            string pre=n;
            //先找直接的回文
            for(int i=size/2;i<size;i++){
                if(size%2)n[i]=n[size/2+(size/2-i)];
                else n[i]=n[size/2-1+(size/2-i)];
            }
            //再找最近的另一个回文
            string temp=n;;
            long a=stol(pre);
            long b=stol(temp);
            if(size%2){
                if(n[size/2]!='9'&&b-a<0){
                    ++n[size/2];
                }
                else if(n[size/2]!='0'&&b-a>0){
                    --n[size/2];
                }
            }
            else{
                if(n[size/2]!='9'&&b-a<0){
                    ++n[size/2];
                    ++n[size/2-1];
                }
                else if(n[size/2]!='0'&&b-a>0){
                    --n[size/2];
                    --n[size/2-1];
                }
            }
            //比较
            long c=stol(n);
            if(abs(b-a)<abs(c-a)){
                n=temp;
            }
            else if(abs(b-a)==abs(c-a)){
                if(b<c) n=temp;
            }
        }
        else{//已知是回文操作
            if(size%2){//奇数
                if(n[size/2]!='0'){
                    --n[size/2];
                }
                else{
                    ++n[size/2];
                }
            }
            else{
                if(n[size/2]!='0'){
                    --n[size/2];
                    --n[size/2-1];
                }
                else{
                    ++n[size/2];
                    ++n[size/2-1];
                }
            }
        }
        return n;
    }
};