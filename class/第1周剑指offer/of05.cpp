#include<bits/stdc++.h>
//22.2.23
/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/
/*  似乎上算法课讲过，快慢指针
    执行效果很好，
    看题解发现了replace函数，
    但c++中的replace似乎不能全部找到。但也挺好用
*/
class Solution {
public:
    string replaceSpace(string s) {
        int prt=0;
        int temp=s.size()-1;
        for(int i=0;i<=temp;i++){
            if(s[i]==' '){
                s.push_back('s');
                s.push_back('s');
                prt+=2;
            }
            prt++;
        }
        prt--;
        while(prt>=0){
            if(s[temp]!=' '){
                s[prt]=s[temp];
                
            }
            else{
                s[prt]='0';
                prt--;
                s[prt]='2';
                prt--;
                s[prt]='%';
            }
            temp--;
            prt--;
        }
        return s;
    }
};
int main()
{
    string str1 = "This is C language";
    string str2 = "C++";
    cout << "Before replacement, string is :"<<str1<<'\n';
    str1.replace(8,1,str2);
    str1.replace(str1.find('T'),1,"%20");
    cout << "Before replacement, string is :"<<str1<<'\n';
}
