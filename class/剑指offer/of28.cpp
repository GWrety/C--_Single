#include"leetcode.h"
//22.2.27
/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
*/
/*
概念没看懂，迷茫了一阵，它是那种演中间折叠的那种对称， 
一定要注意代码优化，要简洁
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return test(root->left,root->right);
    }   
    bool test(TreeNode*A,TreeNode *B){
        if(!A&&!B)return true;
        if(!A||!B||A->val==B->val)return false;
        return test(A->left,B->right)&&test(A->right,B->left);
    }
};