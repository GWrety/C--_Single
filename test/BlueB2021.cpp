#include<iostream>
using namespace std;
class solution1{
public:
    int main(){
        int arr[10];
        for(int i=0;i<10;++i){
            arr[i]=0;
        }
        int ans=1;
        int lag=0;
        while(1){
            int temp=ans;
            while(temp){
                int x=temp%10;
                arr[x]++;
                if(arr[x]>2021){
                    lag=1;break;
                }
                temp/=10;
            }
            if(lag) break;
            ans++;
        }
        cout<<ans-1;
        return 0;
    }
};

