#include <bits/stdc++.h>
using namespace std;


//按照常规想法来说就是模拟整个过程。 
//也可以利用一个栈，不断push提供的pushed。每当遇到和popped相等的就循环判断
//看遍历完之后的辅助栈是不是为空，非空返回false，是空返回true
//!当然这道题目的前提要求是所有元素都不重复。如果重复的话，咋办？
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> temp;
        int aim=0;
        for (size_t i = 0; i < pushed.size(); i++)
        {
            temp.push(pushed[i]);
            while(!temp.empty()&&aim<popped.size()&&temp.top()==popped[aim]){
                temp.pop();
                aim++;
            }
            /* code */
        }
        return temp.empty()? true:false;
        
    }
};

int main()
{
    
    system("pause");
    return 0;
}
