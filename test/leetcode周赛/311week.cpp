#include <bits/stdc++.h>
using namespace std;
//最小公倍数  离n最近的偶数
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2) return 2*n;
        return n;
        
    }
};
//最长字母序串
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1;
        char pres='A';
        int temp=0;
        for(auto i:s){
            if(i==pres+1){
                temp++;
                ans=max(temp,ans);
            }
            else{
                temp=1;
            }
            pres=i;
        }
        return ans;
    }
};

struct TreeNode {
    int val;
       TreeNode *left;
       TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//反转二叉树
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> aim;
        vector<TreeNode*> next;
        next.push_back(root);
        while(!next.empty()){
            for(auto i:next){
                if(i->left==nullptr){
                    next.clear();
                    break;
                }
                aim.push_back(i->left);
                aim.push_back(i->right);
            }
            next.clear();
            for(int i=0;i<aim.size()/2;++i){
                int temp=aim[i]->val;
                aim[i]->val=aim[aim.size()-i-1]->val;
                aim[aim.size()-i-1]->val=temp;
            }
            for(auto i:aim){
                if(i->left==nullptr){
                    break;
                }
                else{
                    next.push_back(i->left);
                    next.push_back(i->right);
                }
            }
            aim.clear();
        }
        return root;
    }
};
//统计分数
//遍历一遍统计字符串前缀可能 放进map
//遍历一遍 统计以map元素为前缀的个数
//再遍历一遍 为答案每个元素赋值
//但因为字典不好匹配 可以用前缀树   遍历一遍构件树+赋值  再遍历一遍取值
class CharTreeNode{
public: 
    int times;
    vector<CharTreeNode*> child;
CharTreeNode(){
        this->times=1;
        this->child=vector<CharTreeNode*>(26,nullptr);
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        CharTreeNode * root=new CharTreeNode();
        for(auto i:words){
            CharTreeNode *now=root;
            for(auto j:i){
                if(now->child[j-'a']==nullptr){
                    now->child[j-'a']=new CharTreeNode();
                }
                else{
                    now->child[j-'a']->times++;
                }
                now=now->child[j-'a'];
            }
        }
        vector<int> ans;
        for(auto i:words){
            CharTreeNode *now=root;
            int temp=0;
            for(auto j:i){
                temp+=now->child[j-'a']->times;
                now=now->child[j-'a'];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    
    system("pause");
    return 0;
}

