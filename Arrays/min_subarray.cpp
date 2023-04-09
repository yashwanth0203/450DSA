/*Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

/*The approach is to use sliding window technique.Take two pointers right and left.Take a variable sum and
keep on adding elements.If sum is equal to target we can directly report size but since we do not know that
we would exactly get target it may be slightly more too so as long as sum is greater than or equal to
target we increase left pointer so as to find minimum size.The minimum is right-left=2.The reason of +2
is +1 for distance between 2 indices like distance between 2nd and 0th index is 2-0+1 and other +1 because
we are finding minimum before left++ that means distance must be +1 than current left pointer.*/
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int minLength=INT_MAX;
        int n=nums.size();
        int sum=0;
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                sum-=nums[left];
                left++;
             minLength=min(minLength,right-left+2);
            }
            right++;
        }
        return minLength==INT_MAX?0:minLength;
}

int main(){
    int target = 7;
    vector<int>nums = {2,3,1,2,4,3};
    cout<<minSubArrayLen(target,nums);
}