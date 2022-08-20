#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    system("pause");
    return 0;
}


struct TreeNode {
    int val;
       TreeNode *left;
       TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//22.8.20
//写一个数组和最左端和最右端的函数处理当前的子树，递归处理即可
//vector在使用括号访问元素时，是不进行越界访问的
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
    TreeNode * fun(vector<int>& nums, int left, int right){
        if(left>right)return nullptr;
        int aim=left;
        int max=nums[left];
        for (size_t i=left+1; i <=right; i++)
        {
            if(max<nums[i]){
                max=nums[i];
                aim=i;
            }
        }
        TreeNode* node = new TreeNode(max);
        node->left=fun(nums,left,aim-1);
        node->right=fun(nums,aim+1,right);
        return node;
    }

};