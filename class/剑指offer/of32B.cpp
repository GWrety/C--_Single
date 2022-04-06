#include"leetcode.h"
//22.2.26
/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
*/
/*
打印二叉树，层次遍历问题
很简单，改了一个入队问题，一遍ac
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> waiting;
        waiting.push(root);
        int now=0,aim_now=1,aim_next=0;
        vector<int> temp1;
        while(waiting.size()!=0){
            TreeNode *temp=waiting.front();
            waiting.pop();
            if(temp->left!=nullptr){
                waiting.push(temp->left);
                aim_next++;
                
            }
            if(temp->right!=nullptr){
                waiting.push(temp->right);
                aim_next++;
            }
            temp1.push_back(temp->val);
            now++;
            if(now==aim_now){
                ans.push_back(temp1);
                temp1.clear();
                aim_now=aim_next;
                aim_next=0;
                now=0;
            }
        }
        return ans;
    }
    
};