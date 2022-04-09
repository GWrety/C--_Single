#include<bits/stdc++.h>
//22.4.3
/*
层次遍历的话就是队列辅助
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            vector<int> temp1;
            queue<Node*> temp2;
            while(!q.empty()){
                Node* temp=q.front();
                q.pop();
                int n=temp->children.size();
                for(int i=0;i<n;++i){
                    temp2.push(temp->children[i]);
                }
                temp1.push_back(temp->val);
            }
            ans.push_back(temp1);
            q=temp2;
        }
        return ans;
    }
};