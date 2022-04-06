#include<bits/stdc++.h>
//22.2.10
/*
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。
*/
/*
    可以用两层循环解决，n（n+1）
    化简：
        似乎和法雷序列一样，
        效果一般
        看题解：
            因为数据量小，暴力解法也很不错
    收获：
        法雷序列就是这道题的答案
        法雷可以优化，1/2之后的可以用1-之前的计算
*/
struct listnode{
    int up;
    int down;
    listnode *next;
    listnode(int a,int b){
        up=a;
        down=b;
        next=nullptr;
    }
};
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        listnode *head=new listnode(0,1);
        listnode *tail =new listnode(1,1);
        head->next=tail;
        function(head,n);
        vector<string> temp;
        listnode *answer=head->next;
        while(answer->next!=nullptr){
            temp.push_back(to_string(answer->up)+"/"+to_string(answer->down));
            answer=answer->next;
        }
        int length=temp.size();
        for(int i=0;i<length-1;i++){
            head=head->next;
            head->up=head->down-head->up;
            temp.push_back(to_string(head->up)+"/"+to_string(head->down));
        }
        return temp;
    }
    void  function(listnode* head,int n){
        listnode * tail=head->next;
        while(tail!=nullptr){
            if(head->down+tail->down<=n){
                listnode * temp= new listnode(head->up+tail->up,head->down+tail->down);
                temp->next=tail;
                head->next=temp;
            }
            else{
                head=head->next;
            }
            tail=head->next;
            if(head->up==1&&head->down==2){
                return;
            }
        }
    }
};








