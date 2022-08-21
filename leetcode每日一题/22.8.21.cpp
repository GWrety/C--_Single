#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int answer=-1;
        //一开始想的是直接遍历，但是需要记住单词的位置以及遍历的状态有点麻烦。 不如先分割成字符串的集合好操作
        istringstream ss(sentence);
        vector<string> words;
        string word;
        int lag=1;
        while(ss >> word) {
            words.push_back(word);
            //if(word.starts_with(searchWord))//这个函数在C++20才有  
            if (std::mismatch(word.begin(),word.end(), searchWord.begin()).second == searchWord.end()){//一个比较迭代器的函数  first代表第一个迭代器不匹配的位置，second代表第二个不匹配的位置
                answer=lag;
                break;
            }
            lag++;
        }
        

        return answer;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
