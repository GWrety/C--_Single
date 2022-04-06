#include<bits/stdc++.h>
//22.3.23
/*
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
*/
/*
这个实际上也是数学思想，就是求法比较巧妙，
用字典树的概念能更容易理解这种抽象方式
*/
//字典树思想
class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } 
            else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};