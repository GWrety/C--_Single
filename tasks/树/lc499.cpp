#include<bits/stdc++.h>
//22.5.11
/*
序列化是将数据结构或对象转换为一系列位的过程，
以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 
您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
编码的字符串应尽可能紧凑。
*/
/*
这道题就是和文件管理系统中的文件数持久化一样
但那是对于一个没有规律的二叉树来说，这道题是二叉搜索树
二叉搜索树的定义是 左边比节点小，右边比节点大
中序遍历之后是一个升序的序列
如果我前序遍历
在恢复时，如果下一个树比我小就继续，如果比我大，且比我上一个小，那么这个就是我的右孩子
如果不是就应该出栈判断上一个 并且不把右孩子有值的节点放入栈中
效率很高了
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string a="";
        if(root!=nullptr){
            a+=to_string(root->val);
            a+=' ';
            if(root->left!=nullptr){
                a+=serialize(root->left);
            }
            if(root->right!=nullptr) {
                a+=serialize(root->right);
            }
        }
        return a;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode*> route;
        TreeNode* root=nullptr;
        int now =0;
        for(auto i:data){
            if(i!=' '){
                now*=10;
                now+=i-'0';
                continue;
            }
            if(root==nullptr){
                root=new TreeNode(now);
                route.push(root);
            }
            else if(route.top()->val>now){
                route.top()->left=new TreeNode(now);
                route.push(route.top()->left);
            }
            else {
                while(1){
                    TreeNode* x=route.top();
                    route.pop();
                    if(route.empty()||route.top()->val>now){
                        x->right=new TreeNode(now);
                        route.push(x->right);
                        break;
                    }
                }
            }
            now=0;
        }
        return root;
    }
};

//参考 istringstream

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream t(data);
        return dfs(t);
    }

    TreeNode* dfs(istringstream& cur){
        string t;
        getline(cur, t, ',');
        if(t == "n") return nullptr;
        TreeNode* root = new TreeNode(stoi(t));
        root->left = dfs(cur);
        root->right = dfs(cur);
        return root;
    }
};



