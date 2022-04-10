#include<bits/stdc++.h>
//22.4.10   2/4
#define all(x) x.begin(),x.end()
class Solution1 {
public:
    int largestInteger(int num) {
        vector<int> two;
        vector<int> one;
        stack<int> ou;
        int now=0;
        while(num!=0){
            int temp=num%10;
            if(temp%2){
                one.push_back(temp);
            }
            else{
                two.push_back(temp);
                ou.push(now);
            }
            num/=10;
            now++;
        }
        sort(all(one));
        sort(all(two));
        now--;
        int ans=0;
        while(!one.empty()||!two.empty()){
            if(one.empty()){
                ans*=10;
                ans+=two.back();
                two.pop_back();
            }
            else if(two.empty()){
                ans*=10;
                ans+=one.back();
                one.pop_back();
            }
            else{
                if(now==ou.top()){
                    ans*=10;
                    ans+=two.back();
                    two.pop_back();
                    ou.pop();
                }
                else{
                    ans*=10;
                    ans+=one.back();
                    one.pop_back();
                }
            }
            now--;  
        }
        return ans;
    }
};

class Solution2 {
public:
    string minimizeResult(string expression) {
        int n=expression.size();
        int num1=0,num2=0;
        int x=0,y=0;
        int pos=-1;
        for(int i=0;i<n;++i){
            if(expression[i]=='+'){
                pos=i;
            }
            else if(pos==-1){
                num1*=10;
                num1+=expression[i]-'0';
                x++;
            }
            else {
                num2*=10;
                num2+=expression[i]-'0';
                y++;
            }
        }
        int temp1,temp2,temp3,temp4;
        int ans1,ans2,ans3,ans4;
        int Max=INT_MAX;
        for(int i=1;i<x;++i){
            temp1=num1;
            temp2=0;
            temp2=temp1%((int)pow(10,i));
            temp1/=((int)pow(10,i));
            for(int j=1;j<y;++j){
                temp3=num2;
                temp4=0;
                temp4=temp3%((int)pow(10,j));
                temp3=temp3/((int)pow(10,j));
                int temp=temp1*(temp2+temp3)*temp4;
                if(temp<Max){
                    ans1=temp1;
                    ans2=temp2;
                    ans3=temp3;
                    ans4=temp4;
                    Max=temp;
                }
            }
        }
        string ans=to_string(ans1)+"("+to_string(ans2)+"+"+to_string(ans3)+")"+to_string(ans4);
        for(int i=1;i<x;++i){
            int temp1 =num1/((int)pow(10,i));
            int temp2=num1%((int)pow(10,i));
            int temp=temp1*(temp2+num2);
            if(temp<Max){
                ans=to_string(temp1)+"("+to_string(temp2)+"+"+to_string(num2)+")";
                Max=temp;
            }
        }
        for(int i=1;i<y;++i){
            int temp1 =num2/((int)pow(10,i));
            int temp2=num2%((int)pow(10,i));
            int temp=temp2*(temp1+num1);
            if(temp<Max){
                ans="("+to_string(num1)+"+"+to_string(temp1)+")"+to_string(temp2);
                Max=temp;
            }
        }
        if(num1+num2<Max){
            ans= "("+to_string(num1)+"+"+to_string(num2)+")";
        }
        return ans;
    }
};

