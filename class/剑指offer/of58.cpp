#include<bits/stdc++.h>
//22.2.23
/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"
*/
/*
    c++没有很好处理字符串的函数，所以初始想法就按规则一个一个+=字符
    看题解：
        String有push_back函数，直接在末尾添加
        还有erase函数，清除字符

*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string answer;
        for(int i=n;i<s.size();i++){
            answer+=s[i];
        }
        for(int i=0;i<n;i++){
            answer+=s[i];
        }
        return answer;
    }
};
//没用过的string函数解法
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for(int i=0;i<n;i++){
            s.push_back(s[i]);
        }
        s.erase(0,n);
        return s;
    }
};