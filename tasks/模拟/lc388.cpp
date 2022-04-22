#include<bits/stdc++.h>
//22.4.20
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<pair<int,int>> wit;
        int ans=0;
        int n=input.size();
        int len=0;
        int start=0,end=-1;
        for(int i=0;i<=n;++i){
            if(i==n||input[i]=='\n'){
                int size=end-start+1;
                if(is_file(input,start,end)){
                    while(!wit.empty()&&wit.back().first>=len) wit.pop_back();
                    int temp=0;
                    for(auto x:wit){
                        temp+=x.second;
                        temp++;
                    }
                    temp+=size;
                    ans=max(ans,temp);
                }
                else{
                    while(!wit.empty()&&wit.back().first>=len) wit.pop_back();
                    wit.push_back(make_pair(len,size));
                }
                len=0;
                start=i+1;
            }
            else if(input[i]=='\t'){
                len++;
                start++;
            }
            else{
                end=i;
            }
        }
        return ans;
    }
    bool is_file(string& input,int start,int end){
        for(int i=start;i<=end;++i){
            if(input[i]=='.'){
                return true;
            }
        }
        return false;
    }
};
