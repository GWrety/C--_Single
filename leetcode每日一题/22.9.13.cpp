#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string temp=to_string(num);
        int ans=num;
        //单调栈 储存从位置到最右端的最大值
        //这里有个小细节，当有一连串相同的数时，应该保留的是最右边哪一个
        vector<int> stack;
        stack.push_back(temp.size()-1);
        for(int j=temp.size()-2;j>=0;--j){
            //!不是等于
            if(temp[j]>temp[stack.back()]){
                stack.push_back(j);
            }
            else{
                stack.push_back(stack.back());
            }
        }
        reverse(stack.begin(),stack.end());
        //寻找每个位置右边有没有比他大的
        for(int i=0;i<temp.size()-1;++i)
        {
            if(temp[i]<temp[stack[i+1]]){
                swap(temp[i],temp[stack[i+1]]);
                ans=stoi(temp);
                break;
            }
        }
        return ans;
        
    }
};

//这个贪心的解法不错
class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxIdx = n - 1;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (charArray[i] > charArray[maxIdx]) {
                maxIdx = i;
            } else if (charArray[i] < charArray[maxIdx]) {
                idx1 = i;
                idx2 = maxIdx;
            }
        }
        if (idx1 >= 0) {
            swap(charArray[idx1], charArray[idx2]);
            return stoi(charArray);
        } else {
            return num;
        }
    }
};

int main()
{
    
    system("pause");
    return 0;
}
