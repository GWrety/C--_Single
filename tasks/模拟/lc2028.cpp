#include<bits/stdc++.h>
//22.3.27
/*
丢骰子平均数问题
缺了n个数据，要补齐
*/
/*
模拟，通过数学计算求出n个数的和
上下不满足直接扔掉
然后从上到下夹逼 
一遍AC过
看了题解发现从数学来说有更优解，先赋满商，再把余数均摊
*/
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=mean*(m+n);
        int sum_m=0;
        for(auto i:rolls){
            sum_m+=i;
        }
        int sum_n=sum-sum_m;
        if(sum_n>6*n||sum_n<n)return {};
        vector<int> ans;
        int temp=6;
        while(sum_n){
            if(sum_n-temp>=n-1){
                ans.push_back(temp);
                sum_n-=temp;
                n--;
            }
            else{
                temp--;
            }
        }
        return ans;
    }
};