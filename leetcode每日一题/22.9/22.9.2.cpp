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
//递归解决
//返回左右和他一样的元素数量
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        findLongest(root,0,ans);
        return ans;
    }
    int findLongest(TreeNode * treenode,int val,int & ans){
        if(treenode==nullptr)return 0;
        int left=findLongest(treenode->left,treenode->val,ans);
        int right=findLongest(treenode->right,treenode->val,ans);
        ans=max(ans,left+right);//此时处理返回结果即可
        if(val==treenode->val){
            return max(left,right)+1;//向上只能用一条边
        }
        else return 0;
    }

};

int main()
{
    
    system("pause");
    return 0;
}
