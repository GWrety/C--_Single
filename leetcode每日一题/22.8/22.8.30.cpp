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

//判断当前节点和val的大小关系，val大的话就他是val的左子树，小的话就在他的右边子树重新考虑
//需要保存前序节点，保证树的连续性
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *temp=nullptr;
        TreeNode *pre=nullptr;
        temp=root;
        TreeNode * aim=new TreeNode(val);
        while(temp!=nullptr){
            if(temp->val<val){
                if(pre!=nullptr){
                    pre->right=aim;
                }
                aim->left=temp;
                break;
            }
            pre=temp;
            temp=temp->right;
            
        }
        if(temp==root)return aim;
        if(temp==nullptr){
            pre->right=aim;
        }
        return root;
    }
};
//牛逼的递归写法
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root || root->val < val) return new TreeNode(val, root, nullptr);
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
