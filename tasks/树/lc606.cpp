#include<bits/stdc++.h>
//22.3.19
/*
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
*/
/*
识别出题目意思就很好做了
但要注意  int转 char！不能转负数
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    string ans="";
    string tree2str(TreeNode* root) {
        if(root){
            ans+=to_string(root->val);
            if(root->left){
                function(root->left);
            }
            if(root->right){
                if(!root->left)ans+="()";
                function(root->right);
            }
        }
        return ans;
    }
    void function(TreeNode * root){
        if(root){
            ans.push_back('(');
            ans+=to_string(root->val);
            if(root->left){
                function(root->left);
            }
            if(root->right){
                if(!root->left)ans+="()";
                function(root->right);
            }
            ans.push_back(')');
        }
    }
};