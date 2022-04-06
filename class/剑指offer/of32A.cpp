#include"leetcode.h"
/*
感觉比of32B还要简单点...为啥这个是中等
直接修改32B代码
*/
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> waiting;
        waiting.push(root);
        while(waiting.size()!=0){
            TreeNode *temp=waiting.front();
            waiting.pop();
            if(temp->left!=nullptr){
                waiting.push(temp->left);
            }
            if(temp->right!=nullptr){
                waiting.push(temp->right);
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};