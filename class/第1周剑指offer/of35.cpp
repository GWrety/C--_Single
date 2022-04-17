#include<bits/stdc++.h>
//22.2.22
/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。
*/
/*
    初始思路：就是赋值，先把链表骨架搭建好，再逐个关节确定random的指向。
        效果还行，但实际复杂度已经是n2了
    看题解优化：    
        题解1 是对地址的高度理解配合 哈希表
        题解2 很巧妙

*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        Node *answer=new Node(head->val);
        Node *temp1=head;
        Node *temp2=answer;
        while(temp1->next!=nullptr){
            temp2->next=new Node(temp1->next->val);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1=head;
        temp2=answer;
        while(temp1!=nullptr){
            if(temp1->random!=nullptr){
                Node *a=head;
                Node *b=answer;
                while(a!=temp1->random){
                    a=a->next;
                    b=b->next;
                }
                temp2->random=b;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return answer;
    }
};
//题解1  回溯+哈希表
//对地址的理解要加深
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};
//题解2 迭代+节点拆分  原地解法 很妙 ！！！
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};
