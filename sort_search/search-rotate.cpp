/*There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k
(1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0],
nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it
is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.*/


/*Here the array is divided into two halves left and right both of which are sorted.But we need to know
which of them is right or left.This can be done by comparing the element with left element.Since the 
left half is increasing from the left element if the element is greater than left it means that 
it is the left array but if the element is less than left it means that we are in the right half
of the array.Now there arises two cases in each left or right part.In the left half if the target is
greater than the element we can increase low also if target is less than left which means it is in 
right half we do the same.Else we decrease the high.Now in the right half of the array we need to check
whether the target is less than mid if its true then we do high=mid-1 similarly when target is more
than right we do high=mid-1 else low=mid+1.This is the approach. */
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            //Left sorted array
            if(nums[mid]>=nums[low]){
                //Search in right sorted array
                if(nums[mid]<target || target<nums[low])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else{
                if(nums[mid]>target || target>nums[high])
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
        return -1;
}

int main(){
    vector<int>nums={4,5,6,7,0,1,2};
    cout<<search(nums,2);
}