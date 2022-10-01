#include <bits/stdc++.h>
using namespace std;
//设计链表殴打实现
class MyLinkedList {
public:
    struct node
    {
        int val;
        node * next;
        node(int x){
            next=nullptr;
            val= x;
        }
        node (){
            val=0;
            next=nullptr;
        }
    };
    int size;
    node * root;
    MyLinkedList() {
        root= new node();
        size=0;
    }
    
    int get(int index) {
        if(index>=size) return -1;
        node *temp=root->next;
        for(int i=0;i<index;++i){
            temp=temp->next;
        }
        return temp->val;
    }
    void addAtHead(int val) {
        node *newnode =new node(val);
            newnode->next=root->next;
            root->next=newnode;
        size++;
    }
    void addAtTail(int val) {
        node *newnode =new node(val);
        node * temp=root;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        size++;
    }
    void addAtIndex(int index, int val) {
        if(index<=0) this->addAtHead(val);
        else if(index<size){
            node *newnode =new node(val);
            node *temp=root->next;
            for(int i=0;i<index-1;++i){
                temp=temp->next;
            }
            node *tp=temp->next;
            temp->next=newnode;
            newnode->next=tp;
            size++;
        }
        else if(index==size) this->addAtTail(val);   
        else{
            return;
        }
    }
    void deleteAtIndex(int index) {
        if(index<0||index>=size) return;
        node *temp=root;
        for(int i=0;i<=index-1;++i){
            temp=temp->next;
        }
        node *tp=temp->next;
        temp->next=temp->next->next;
        delete tp;
        size--;
    }
};
int main()
{
    
    system("pause");
    return 0;
}
