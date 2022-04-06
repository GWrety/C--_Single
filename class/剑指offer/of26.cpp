#include"leetcode.h"
//22.2.27
/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
*/
/*
    其实没有那么多好用的办法，遍历检验就行了
*/
class Solution {
public:
    int real_tag=0;
    TreeNode* PB=nullptr;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr||B==nullptr) return false;
        PB=B;
        function(A);
        return real_tag;
    }
    void function(TreeNode*A){
        if(real_tag)return;
        if(A==nullptr)return;
        if(A->val==PB->val){
            if(!test(A,PB)){real_tag=1;
            return;
            }
        }
        function(A->left);
        function(A->right);
    }
    bool test(TreeNode *A,TreeNode*B){
        if(A==nullptr&&B!=nullptr) return 1;
        if(B==nullptr) return 0;
        if(A->val==B->val){
            return test(A->left,B->left)+test(A->right,B->right);
        }
        return 1;
    }
};