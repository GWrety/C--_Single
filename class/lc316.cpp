#include<bits/stdc++.h>
//22.4.4
/*
一定是大的在后面，小的在前面最好
就是尽量保证顺序排列

先放最大的： 保证选的都向前放且离他最近，不行再放后面 
先放最小的，保证选的都向后放且离他最近，不行再放前面
有问题：必须考虑全局 

看题解是 单调栈
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        for (char ch : s) {
            num[ch - 'a']++;
        }
        string stk;
        for (char ch : s) {
            if (!vis[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } 
                    else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};
