#include<bits/stdc++.h>
//22.2.25
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，
并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为1。  

*/
/*
这题在做的时候想到是二分了，but在实践的时候对于
    .... .............
        .
    ............ .....
                .
    以上者两种情况如何二分，不知道如何解决
    看题解才知道可以把右边界向内移动一点
    有点难
    而且知道了
    对于 mid=(left_right)/2这个式子
    用mid=left+(right-left)/2可以避免溢出   有时候left+right会很大，可能导致溢出
*/
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left=0,right=numbers.size()-1;
        if(numbers[0]<numbers[right]) return numbers[0];
        int mid;
        while(left<right){
            mid=(left+right)/2;
            if(numbers[mid]>numbers[left]){
                left=mid+1;
                if(numbers[left]<numbers[left-1]) return numbers[left];
            }
            else if(numbers[mid]==numbers[left]){
                left++;
            }
            else{
                right=mid;
            }
        }
        return numbers[right];
    }
};