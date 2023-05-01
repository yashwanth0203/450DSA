/*Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal
to the sum of all the numbers strictly to the index's right.If the index is on the left edge of the array,
then the left sum is 0 because there are no elements to the left. This also applies to the right edge of 
the array.Return the leftmost pivot index. If no such index exists, return -1.*/

/*You might have already guessed the approach that is look at both leftSum and rightSum for each element.
We can create two vectors leftSum and rightSum.but since we wont be visiting them again no need to make
two vectors just two vectors would suffice where leftSum would increase at each iteration and rightSum
would decrease at each iteration while iterating from left to right.Hence this can be done in O(n) time.*/

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int rightSum=0;
        for(int i=0;i<nums.size();i++)
            rightSum+=nums[i];
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            rightSum-=nums[i];
            if(leftSum==rightSum)
                return i;
            leftSum+=nums[i];
        }
        return -1;
}

int main(){
    vector<int>arr={1,7,3,6,5,6};
    cout<<pivotIndex(arr);
}