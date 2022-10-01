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
//找出重复的子树 说明有两个节点的结构是一样的
//最基础的做法是遍历一遍找出所有的节点，n2 上三角 遍历一遍 用一个函数判断两个节点是否相等
//想想更优雅的   父节点和子节点一定不用比较  但这个化简的也不是很多  
//能像到的化简方式就是 前序遍历过程中扩充已遍历的节点 让当前节点与所有节点进行比较  这种写法比拿出整个序列更好一点点
//上面最基础的算法超时    最终极的要求就是 如何hash一个 二叉树

//答案解法1 使用序列化进行唯一表示
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    string dfs(TreeNode* node) {
        if (!node) {
            return "";
        }
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
        if (auto it = seen.find(serial); it != seen.end()) {
            repeat.insert(it->second);
        }
        else {
            seen[serial] = node;
        }
        return serial;
    }

private:
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> repeat;
};


//答案解法2 使用三元组进行唯一表示
//!亏贼 在哈希使用 自定义的哈希函数
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        auto tri = tuple{node->val, dfs(node->left), dfs(node->right)};
        if (auto it = seen.find(tri); it != seen.end()) {
            repeat.insert(it->second.first);
            return it->second.second;//不存重复的
        }
        else {
            seen[tri] = {node, ++idx};
            return idx;
        }
    }

private:
    static constexpr auto tri_hash = [fn = hash<int>()](const tuple<int, int, int>& o) -> size_t {
        auto&& [x, y, z] = o;
        return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
    };

    //第三个参数是哈希函数的哈希对象
    unordered_map<tuple<int, int, int>, pair<TreeNode*, int>, decltype(tri_hash)> seen{0, tri_hash};
    unordered_set<TreeNode*> repeat;
    int idx = 0;
};



class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> wait;
        vector<int> ans;
        //对于一类子树如何去除重复的？
        //那就是 如果这条子树已经被用过了 那么就不再添加他了  把原有的那个做个标记  最后提取所有标记即可
        //也就是说 最后取到的子树 一定是前序遍历在前面的子树
        fun(root,wait,ans);
        vector<TreeNode *> res;
        for (size_t i = 0; i < ans.size(); i++)
        {
            if(ans[i]){
                res.push_back(wait[i]);
            }
        }
        return res;

    }
    void fun(TreeNode * now,vector<TreeNode*> &wait, vector<int> &ans){
        if(now==nullptr) return;
        for (size_t i = 0; i < wait.size(); i++)
        {
            if(issimilar(now,wait[i])){
                ans[i]=1;
                fun(now->left,wait,ans);
                fun(now->right,wait,ans);
                return;
            }
        }
        wait.push_back(now);
        ans.push_back(0);
        fun(now->left,wait,ans);
        fun(now->right,wait,ans);
    }
    bool issimilar(const  TreeNode * a, const TreeNode * b){
        if(a==nullptr&&b==nullptr) return true;
        else if (a!=nullptr&&b!=nullptr&&a->val==b->val)
        {
            return issimilar(a->left,b->left)&&issimilar(a->right,b->right);
        }
        else return false;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
