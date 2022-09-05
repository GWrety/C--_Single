#include<bits/stdc++.h>
//22.2.22
/*
    定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
*/
/*
    倒插法 定义头指针要实例化一下，小纠缠。
    这道题秀递归？？
    试试
    自己写了一种简单点的递归解法
    题解提供了一种更巧妙和清晰的递归解法
*/
struct ListNode {
    int val;
   ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//倒插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode * answer=new ListNode(0) ;
        while(head->next!=nullptr){
            ListNode *temp;
            temp=head->next;
            head->next=answer->next;
            answer->next=head;
            head=temp;
        }
        answer->val=head->val;
        return answer;
    }
};
//简单递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        return function(head,nullptr);
    }
    ListNode *function(ListNode * now,ListNode *pre){
        if(now->next==nullptr) {
            now->next=pre;
            return now;
        }
        ListNode * temp=now->next;
        now->next=pre;
        return function(temp,now);
    }
};
//复杂递归 很秀
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};