#include<bits/stdc++.h>
//22.3.14
/*
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。
*/
/*
签到题？双遍历
效果很差，应该有更好地解法
果然是哈希  n2 ->n
总之还是签到题  不写了 过了吧
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int sum=0;
        for(int i=0;i<list1.size();++i){
            for(int j=0;j<list2.size();++j){
                if(list1[i]==list2[j]){
                    if(ans.empty()){
                        ans.push_back(list1[i]);
                        sum=i+j;
                    }
                    else if(i+j==sum){
                        ans.push_back(list1[i]);
                    }
                    else if(i+j<sum){
                        ans.clear();
                        ans.push_back(list1[i]);
                        sum=i+j;
                    }
                }
            }
        }
        return ans;
    }
};