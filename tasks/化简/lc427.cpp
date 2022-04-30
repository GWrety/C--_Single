#include<bits/stdc++.h>
//22.4.29
/*
简单拆分，就是把x和y容易搞混
可以用前缀和优化 待办
*/
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node *temp;
        int n=grid.size();
        temp=func(grid,0,0,n);
        return temp;
    }
    Node* func(vector<vector<int>>&grid,int x,int y,int m){
        Node* temp =new Node;
        int val=grid[y][x];
        int lag=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                if(val!=grid[y+i][x+j])lag=1;
            }
        }
        if(lag){
            temp->isLeaf=0;
            temp->val=1;
            temp->topLeft=func(grid,x,y,m/2);
            temp->topRight=func(grid,x+m/2,y,m/2);
            temp->bottomLeft=func(grid,x,y+m/2,m/2);
            temp->bottomRight=func(grid,x+m/2,y+m/2,m/2);
        }
        else{
            temp->isLeaf=1;
            temp->val=val;
        }
        return temp;
    }
};