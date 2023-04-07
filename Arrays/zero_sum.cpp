/*Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one)
 with 0 sum.*/

#include <bits/stdc++.h>
using namespace std;

/*The brute force approach would be to run the two loops and check for each subarray whether the sum 
equals 0 or not.But the efficient approach would be to maintain a prefix array and keep track of sum
till that point.At any point of time if prefix sum becomes 0 we can understand that there is a subarray
or if prefix sum repeats again we can say that. Now the reason being,the prefix sum remains same
even if we add 0 to the prefix sum so the sum remains same thus we can know that the subarray between
these two same prefix sums give a sum of 0.This is intuition behind this*/

 bool subArrayExists(int arr[], int n)
    {
        int sum=0;
        unordered_set<int>sumSet;
        for(int i=0;i<n;i++){
             sum+=arr[i];
            
        if(sumSet.find(sum)!=sumSet.end()||sum==0)
            return true;
        sumSet.insert(sum);
        }
        return false;
    }

int main(){
    int arr[]={2,-1,3};
    cout<<subArrayExists(arr,4);
    return 0;
}