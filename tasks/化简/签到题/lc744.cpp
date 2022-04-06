#include<bits/stdc++.h>
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        char ans='0';
        for(auto &temp:letters){
            if(temp>target){
                ans=temp;
                break;
            }
        }
        return ans=='0'? letters[0]:ans;
    }
};