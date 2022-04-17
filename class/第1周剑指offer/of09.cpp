#include<bits/stdc++.h>
//22.2.21
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
/* 
    初始想法：两个栈模拟队列，一个栈存real顺序，另一个负责在执行deletehead时当作temp
    结果：效率很差
    优化：
        1.简化不必要操作，不需要每次deletehead时都倒腾一遍，保持原状就好，主要解决了连续同一操作的情况。
            结果：提高一点
        2.尝试直接用stl中的queue 空间复杂度也不高
    看题解：
        无收获，待解决。
*/
class CQueue {
public:
    stack<int> real;
    stack<int> temp;
    CQueue() {
    }
    void appendTail(int value) {
        if(temp.size()!=0){
            int a;
            while(temp.size()!=0){
                a=temp.top();
                real.push(a);
                temp.pop();
            }
        }
        real.push(value);
    }
    int deleteHead() {
        if(temp.size()!=0){
            int a;
            a=temp.top();
            temp.pop();
            return  a;
        }
        else{   
            if(real.size()==0)return -1;
            else if(real.size()==1){
                int a= real.top();
                real.pop();
                return a;
            }
            else{
                int a;
                while(real.size()!=1){
                    a=real.top();
                    temp.push(a);
                    real.pop();
                }
                int answer=real.top();
                real.pop();
                return answer;
            }
        }
    }
};
