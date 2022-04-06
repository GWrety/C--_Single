#include<bits/stdc++.h>
//22.3.18
/*
给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。
若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
*/
/*
这道题虽然是简单题，但感觉思路好难
字典树不知道如何使用，排序之后也感觉不好操作
没读懂题目  必须要求一个一个添加 那样的话排序之后就很好做了
substr(int start,int length)截取字符串

这个字典树还是妙啊，加一个is_end的标识符就可以识别再去的每条路径上是不是有前缀
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());//排序
        set<string> s;//集合
        string ans;//返回的答案
        for(int i=0;i<words.size();i++){//遍历
            if(words[i].size()==1||s.count(words[i].substr(0,words[i].size()-1))){
                ans=words[i].size()>ans.size()?words[i]:ans;
                s.insert(words[i]);
            }      
        }
        return ans;
    }
};
//字典树
class Trie {
public:
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
    
    bool insert(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (!node->children[index]->isEnd) {//少了前缀
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto & word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto & word : words) {
            if (trie.search(word)) {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};


