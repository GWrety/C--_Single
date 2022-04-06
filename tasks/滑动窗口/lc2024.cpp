#include<bits/stdc++.h>
//22.3.29
/*
一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。
老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。
给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：
每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。
*/
/*
经典滑窗问题
这道题用其他思路基本上不能实现，只能通过滑窗问题去探测
保证这个窗口内异字符的个数小于k！！！
不断伸长。
*/
//常规想法是要分别维护一遍F T窗口 
class Solution {
public:
    int maxConsecutiveChar(string& answerKey, int k, char ch) {
        int n = answerKey.length();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != ch;
            while (sum > k) {
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                maxConsecutiveChar(answerKey, k, 'F'));
    }
};
//二合一升级版
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int cntT = 0, cntF = 0, ans = 0;
        
        for (int left = 0, right = 0; right < n; ++right) {
            if (answerKey[right] == 'T') cntT++;
            else cntF++;
            if (cntT > k && cntF > k) {//这里的if可以修改成while 改成if尽管会有不是答案的解，但不会扩充答案，答案是正确的
                if (answerKey[left] == 'T') cntT--;
                else cntF--;
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};



