#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
       TreeNode *left;
       TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




//BTS 把所有超过范围的树节点都剔除掉
//对于那种兄弟之间父亲丢失需要重写定义父子关系的情况 是不可能的 因为是二叉搜索树，
//父节点一定是两节点的区间，不存在一个区间 把中间的数字丢掉而两端存在
//递归解决
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return findson(root,low,high);
    }
    TreeNode* findson(TreeNode *temp,int low,int high){
        if(temp==nullptr)return nullptr;
        else if(temp->val>=low&&temp->val<=high){
            temp->left=findson(temp->left,low,high);
            temp->right=findson(temp->right,low,high);
            return temp;
        }
        else if(temp->val<low){
            return findson(temp->right,low,high);
        }
        return findson(temp->left,low,high);
    }
};




int main()
{
    
    system("pause");
    return 0;
}

