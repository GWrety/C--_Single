#include<bits/stdc++.h>
//22.3.19
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/
/*
括号匹配问题
有两种结构：
一种是()单个闭环   直接判断就行  2+dp[n-2]
一种是(.....)中间间隔好几个闭环   就要去找他断掉之前的部分
而解法二用栈能很好的识别括号匹配问题，
就是在处理断档问题上需要识别
压缩空间的话可以遍历两边
一题三解  长见识了
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};
//栈版本
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } 
            else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } 
                else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};
//最小空间的解法
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } 
            else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } 
            else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};



