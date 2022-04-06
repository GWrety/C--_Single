#include"leetcode.h"
//22.2.26
/*
请实现一个函数按照之字形顺序打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
其他行以此类推。
*/
/*
是of32B的变式，还在想把vector翻转，看了一眼题解发现有个栈字 就意识到是把queue换成stack 完美解决
稍等  发现其实有很大的问题 修改  防不胜防  还要调整左右入栈的顺序   还是翻转vector好用......
题解懒得看了  发现如果vector能双端插入就好了（python和java里似乎有双端list？）
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> waiting;
        stack<TreeNode*> temp2;
        waiting.push(root);
        int now=0,aim_now=1,aim_next=0;
        vector<int> temp1;
        int lag=0;
        while(waiting.size()!=0){
            TreeNode *temp=waiting.top();
            waiting.pop();
            if(lag){
                if(temp->left!=nullptr){
                    temp2.push(temp->left);
                    aim_next++;
                    
                }
                if(temp->right!=nullptr){
                    temp2.push(temp->right);
                    aim_next++;
                }
            }
            else{
                if(temp->right!=nullptr){
                    temp2.push(temp->right);
                    aim_next++;
                }
                if(temp->left!=nullptr){
                    temp2.push(temp->left);
                    aim_next++;
                    
                }
                
            }
            temp1.push_back(temp->val);
            now++;
            if(now==aim_now){
                ans.push_back(temp1);
                temp1.clear();
                waiting=temp2;
                while(temp2.size()!=0)temp2.pop();
                aim_now=aim_next;
                aim_next=0;
                now=0;
                lag++;
            }
        }
        return ans;
    }
};