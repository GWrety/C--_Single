#include<bits/stdc++.h>


struct TreeNode {
    int val;
       TreeNode *left;
       TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//主要思路就是先求出数的高度，把矩阵建立好，在递归的赋值
//如果是递归的构建树也可以传参数传引用，
//上述两种方法都需要先求出树的深度
class Solution {
public:

    vector<vector<string>> printTree(TreeNode* root) {
        int height=findHeight(root);
        //这个树高度和列数之间的数学关系要注意一下
        //解法一 先构建矩阵，再赋值
        //还有一个是按公式推算，直接赋值
        vector<vector<string>> ans(height+1,vector<string>(pow(2,height+1)-1));
        fun(ans,0,0,pow(2,height+1)-2,root);
        return ans; 
        //解法二， 直接递归构建
        //需要写一个迭代函数，递归无法再两条路径赋值同一个对象   有点麻烦意义不大  最快的还是求公式
        // vector<vector<string>>  ans;
        // for (size_t i = 0; i < height+1; i++)
        // {
        //     vector<string> temp;

        //     ans.push_back(temp);
        // }
        // return ans;
    }
    void fun(vector<vector<string>>& ans,int row,int left,int right,TreeNode * temp){
        if(temp==nullptr)return;
        int mid =left+(right-left)/2;
        ans[row][mid]=to_string(temp->val);
        fun(ans,row+1,left,mid-1,temp->left);
        fun(ans,row+1,mid+1,right,temp->right);
    }
    int findHeight(TreeNode * temp){
        if(temp==nullptr) return 0;
        if(temp->left==nullptr&&temp->right==nullptr) return 0;
        else return 1+max(findHeight(temp->left),findHeight(temp->right));
    }
};


int main()
{
    vector<int> nums(5);
    nums[0]=1;
    cout<<nums[5];
    system("pause");
    return 0;
}

