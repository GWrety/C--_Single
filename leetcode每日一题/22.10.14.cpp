#include <bits/stdc++.h>
using namespace std;

//分治的思想还是很高级的
//对于这个问题  这种栈解法显然是更高级的
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};