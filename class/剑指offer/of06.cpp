#include<bits/stdc++.h>
//22.2.22
/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）
*/
/*
    这道题里链表头节点没有空节点。
    首先想法：用栈储存解决
    看题解：用求长度直接反过来赋值效率更高
*/
struct ListNode {
    int val;
   ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//栈版本
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> temp;
        vector<int> answer;
        while(head!=nullptr){
            temp.push(head->val);
            head=head->next;
        }
        while(temp.size()!=0){
            answer.push_back(temp.top());
            temp.pop();
        }
        return answer;
    }
};
//直接赋值版本
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int len=getlen(head);
        vector<int> answer;
        for(int i=1;i<=len;i++){
            answer[len-i]=head->val;
            head=head->next;
        }
        return answer;
    }
    int getlen(ListNode * head){
        int len=0;
        while(head!=nullptr){
            len++;
            head=head->next;
        }
        return len;
    }
};