#include<bits/stdc++.h>
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dir={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> Hash;
        int n=words.size();
        for(int i=0;i<n;i++){
            string temp;
            for (auto k:words[i])
            {
                temp+=dir[k-'a'];
            }
            Hash[temp]++;
        }
        return Hash.size();
    }
};