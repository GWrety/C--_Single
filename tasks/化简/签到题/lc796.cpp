#include<bits/stdc++.h>
//22.4.7
/*
给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。

s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 

例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
*/
/*
签到题
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int start=0;
        int n=s.size();
        if(goal.size()!=n) return false;
        int i=0;int j;
        while(start<n){
            if(s[start]==goal[0]){
                for(j=0,i=start;i<n;++i,++j){
                    if(s[i]!=goal[j]){
                        break;
                    }
                }
            }
            if(i==n) {
                for(int k=0;j<n;++j,++k){
                if(goal[j]!=s[k]){
                    break;
                }
                }
                if(j==n) return true;
                break;
            }
            start++;
            }
        return false;
    }
};
