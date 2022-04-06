#include<bits/stdc++.h>
//22.3.5
/*给你两个字符串 a 和 b，请返回 这两个字符串中 最长的特殊序列  。如果不存在，则返回 -1 。
「最长特殊序列」 定义如下：该序列为 某字符串独有的最长子序列（即不能是其他字符串的子序列） 。
字符串 s 的子序列是在从 s 中删除任意数量的字符后可以获得的字符串。
例如，"abc" 是 "aebdc" 的子序列，因为删除 "aebdc" 中斜体加粗的字符可以得到 "abc" 。
"aebdc" 的子序列还包括 "aebdc" 、 "aeb" 和 "" (空字符串)。
*/
/*
简单问题，在分析清楚问题的规模后，只有两种情况，
不等直接返回，相等不一样返回长度，一样返回-1
*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()!=b.size())
            return a.size()>b.size()? a.size():b.size();
        for(int i=0;i<a.size();++i){
            if(a[i]!=b[i]){
                return a.size();
            }
        }
        return -1;
    }
};
