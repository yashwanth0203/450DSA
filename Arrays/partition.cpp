/*Given an array of size n and a range [a, b]. The task is to partition the array around the range
 such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.*/

/*Remember whenever we need to sort the array into three parts use dutch flag algorithm.This algorithm is
clearly explained in sort012 problem.*/
#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& nums,int a, int b)
    {
        int left=0;
        int mid=0;
        int right=nums.size()-1;
    for(int i=0;i<nums.size();i++){
        if(nums[mid]<a){
            swap(nums[mid],nums[left]);
            mid++;
            left++;
        }
        else if(nums[mid]>=a && nums[mid]<=b)
            mid++;
        else{
            swap(nums[mid],nums[right]);
            right--;
        }
    }
}

int main(){
    vector<int>arr={2,8,3,7,5,6,4,1};
    threeWayPartition(arr,3,6);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}