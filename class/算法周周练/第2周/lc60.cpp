#include<bits/stdc++.h>
//22.2.28
/*
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
*/
/*
全排列问题,只要思考清楚他的排序规则，还是挺简单的
实际原理就是 康托展开 https://baike.baidu.com/item/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80/7968428
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int* factorial =new int [n+1];
        factorial[0]=1;
        for(int i=1;i<=n;i++){
            factorial[i]=i*factorial[i-1];
        }
        string ans;
        char *used=new char [n+1];
        for(int i=1;i<=n;i++)used[i]='0';
        int tag=n-1;
        while(k!=1){
            if(k==factorial[tag+1]){
                for(int i=n;i>=1;--i){
                    if(used[i]=='0'){
                        ans+=to_string(i);
                        used[i]='1';
                    }
                }
                return ans;
            }
            for(int i=0;i<=tag;++i){
                if(i*factorial[tag]<k&&k<=(i+1)*factorial[tag]){
                    int temp=1;
                    while(used[temp]!='0')++temp;
                    for( int j=1;j<i+1;++temp){
                        if(used[temp+1]=='0') j++;
                    }
                    ans+=to_string(temp);
                    used[temp]='1';
                    k-=i*factorial[tag];
                    --tag;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(used[i]=='0'){
                ans+=to_string(i);
            }
        }
        return ans;
    }
};