/*Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.*/


//To get intuition watch striver video
#include <bits/stdc++.h>
using namespace std;

    void nextPermutation(vector<int>& nums) {
        int index1=-1,index2;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index1 = i;
                break;
            }
        }
        if(index1>=0)
        {
            for(int i=nums.size()-1;i>=index1;i--)
            {
                if(nums[i]>nums[index1])
                {
                    index2 = i;
                    break;
                }
            }
            swap(nums[index1],nums[index2]);
            reverse(nums.begin()+index1+1,nums.end());
        }
        else
        {
            reverse(nums.begin(),nums.end());
        }
    }

int main(){
    vector<int>arr={1,3,2,4,5};
    nextPermutation(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}