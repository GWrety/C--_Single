#include"leetcode.h"
//22.2.27
/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/
/*
不就是翻转节点嘛,咋弄都行
*/
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        swap(root);
        return root;
    }
    void swap(TreeNode *temp){
        if(temp==nullptr) return;
        TreeNode *a;
        a=temp->left;
        temp->left=temp->right;
        temp->right=a;
        swap(temp->left);
        swap(temp->right);
    }
};