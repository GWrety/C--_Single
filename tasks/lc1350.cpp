#include<bits/stdc++.h>
/*
二叉搜索树
左边小于它右边大于它
中序遍历是自己的顺序
最笨的办法两次中序遍历 合并

用栈辅助 也能做 
栈里放路径
有左孩子就放左孩子
出栈了就把右孩子放进去 循环

用morris 二叉线索树也能做 很牛逼的做法 迭代器
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
    void inorder(TreeNode *node, vector<int> &res) {
        if (node) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);

        vector<int> merged;
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (true) {
            if (p1 == nums1.end()) {
                merged.insert(merged.end(), p2, nums2.end());
                break;
            }
            if (p2 == nums2.end()) {
                merged.insert(merged.end(), p1, nums1.end());
                break;
            }
            if (*p1 < *p2) {
                merged.push_back(*p1++);
            } else {
                merged.push_back(*p2++);
            }
        }
        return merged;
    }
};
