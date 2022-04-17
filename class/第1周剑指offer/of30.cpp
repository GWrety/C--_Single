#include<bits/stdc++.h>
//22.2.21
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
*/
/*
    不考虑题目时间复杂度限制，在min时就用遍历，能过，效果很差。
    为什么题目没有要求top的复杂度？
    优化：无思路
    看题解：
        1.没说能用栈啊（原来用的是int数组）   
            辅助栈：保底元素，及时出牌
    min题解   没用栈   有点意思 标记一下就行了  按负数区分转换
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>A;
    stack<int>B;
    MinStack() {
        
    }
    void push(int x) {
        A.push(x);
        if(B.size()==0||x<=B.top()){
            B.push(A.top());
        }
    }
    void pop() {
        if(A.top()==B.top()){
            B.pop();
        }
        A.pop();
    }
    int top() {
        return A.top();
    }
    int min() {
        return B.top();
    }
};