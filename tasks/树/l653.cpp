#include<bits/stdc++.h>
/*
BST？深度优先搜索？
是和两数之和一样的解法？确实能过，但是效果不是很好
当然也可以中序遍历之后把数组顺序提取出来，在从中间开始查找就好了
利用二叉搜索树的性质，中序遍历就是顺序的
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
    unordered_map<int,int> hash;
    bool findTarget(TreeNode* root, int k) {
        int lag=0;
        function(root,k,lag);
        return lag;
    }
    void function(TreeNode*root,int& k,int& lag){
        if(!root||lag)return;
        if(hash[root->val]) {
            lag=1;
            return;
        }
        hash[k-root->val]++;
        function(root->left,k,lag);
        function(root->right,k,lag);
    }
};