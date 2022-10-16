#include <bits/stdc++.h>
using namespace std;
//n<=2000

/*
    vector<int> num;
    auto x= num.begin();
    int a=*x;
    迭代器的用法和指针相似？
*/
//itme1
//由于题目保证了dislike数组中，第一个数字是小于第二个数字的，
//所以我们首先按第一个数字的大小进行排序。 然后遍历一遍。将两者分在不同的集合
//首先对于俩个数字至少有一个已经存在于集合中的情况，很好解决
//如果当前遍历到两个数字都不曾存在与集合中 留到最后 
//如果本次没有dislikes中的元素被消除说明是全新的问题  随机重新赋值即可
// 方法是没有问题的 就是时间复杂度很高。过不了
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        set<int> set1;
        set<int> set2;
        while(!dislikes.empty()){
            sort(dislikes.begin(),dislikes.end(),greater());
            auto x=dislikes.begin();
            int lag=1;
            while (x!=dislikes.end())
            {
                int a=(*x)[0];
                int b=(*x)[1];
                if(set1.find(a)!=set1.end()||set2.find(a)!=set2.end()){
                    if(set1.find(a)!=set1.end()){
                        //集合存在冲突
                        if(set1.find(b)!=set1.end()) return false;
                        set2.insert(b);
                    }
                    else{
                        if(set2.find(b)!=set2.end()) return false;
                        set1.insert(b);
                    }
                }
                else if(set1.find(b)!=set1.end()||set2.find(b)!=set2.end()){
                    if(set1.find(b)!=set1.end()){
                        //集合存在冲突
                        if(set1.find(a)!=set1.end()) return false;
                        set2.insert(a);
                    }
                    else{
                        if(set2.find(a)!=set2.end()) return false;
                        set1.insert(a);
                    }
                }
                else{
                    x++;
                    continue;
                }
                x=dislikes.erase(x);
                lag=0;
            }
            if(lag){
                int a=(*dislikes.begin())[0];
                int b=(*dislikes.begin())[1];
                set1.insert(a);
                set2.insert(b);
                dislikes.erase(dislikes.begin());
            }
        }

        return true;
    }
};
//item2



int main()
{
    system("pause");
    return 0;
}
