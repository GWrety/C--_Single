#include<bits/stdc++.h>
//22.4.21
class Solution {
public:
    string toGoatLatin(string sentence) {
        int n=sentence.size();
        string ans="";
        int start=0;
        string index="a";
        for(int i=0;i<=n;++i){
            if(i==n||sentence[i]==' '){
                if(start!=0)
                ans+=' ';
                string temp=sentence.substr(start,i-start);
                if(temp[0]!='a'&&temp[0]!='e'&&temp[0]!='i'&&temp[0]!='o'&&temp[0]!='u'&&temp[0]!='A'&&temp[0]!='E'&&temp[0]!='I'&&temp[0]!='O'&&temp[0]!='U'){
                    char a=temp[0];
                    temp.erase(temp.begin());
                    temp.push_back(a);
                }
                temp+="ma";
                temp+=index;
                ans+=temp;
                index+="a";
                start=i+1;
            }
        }
        return ans;  
        }
};