#include <bits/stdc++.h>
using namespace std;

//模拟，遍历一遍数组 对每个元素从他的后一个位置开始寻找第一个比他小的元素进行折扣
//n2  应该没什么简单的方法
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for (size_t i = 0; i < prices.size(); i++)
        {
            int aim=prices[i];
            /* code */
            for (size_t j = i+1; j < prices.size(); j++)
            {   
                if(prices[j]<=aim){
                    aim-=prices[j];
                    break;
                }
                /* code */
            }
            ans.push_back(aim);
        }
        return ans;
    }
};
//可以用单调栈来优化时间复杂度
// n  巧妙的是倒序遍历  如果当前的值比栈顶的小 那么之后的元素不可能便不可能用这个栈顶的元素，直接pop即可
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.emplace(prices[i]);
        }
        return ans;
    }
};
int main()
{
    system("pause");
    return 0;
}
