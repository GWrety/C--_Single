#include<bits/stdc++.h>
//22.3.10
/*
前序遍历，签到题
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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        function(root,ans);
        return ans;
    }
    void function(Node *temp,vector<int>& ans){
        if(!temp) return;
        ans.push_back(temp->val);
        for(int i=0;i<(temp->children.size());++i){
            if(temp->children[i]){
            function(temp->children[i],ans);
            }
        }
        return;
    }
};