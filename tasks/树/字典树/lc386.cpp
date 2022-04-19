#include<bits/stdc++.h>
/*
强制要求时间复杂度是O（n）
空间复杂度是O（1）
上一道类似的题目是用字典树求解的
理论上可以模拟字典树的遍历过程
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int now=1;
        ans.push_back(1);
        while(ans.size()<n){
            if(now*10<=n){
                now*=10;
                ans.push_back(now);
            }
            else if(now+1<=n&&(now+1)%10!=0){
                now+=1;
                ans.push_back(now);
            }
            else{
                now/=10;
                while((now+1)%10==0) now/=10;
                now++;
                ans.push_back(now);
            }
        }
        return ans;
    }
};