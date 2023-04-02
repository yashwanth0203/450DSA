//Given an integer array nums, find the subarray with the largest sum, and return its sum.
#include <bits/stdc++.h>
using namespace std;

//O(n) Approach 
int maxSubArray(vector<int>& nums) {
        int curr_sum=nums[0];
        int max_sum=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_sum=max(nums[i],curr_sum+nums[i]);
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
}

//O(n3) solution
int bruteforce(vector<int>& nums){
    int sum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int currsum=0;
            for(int k=i;k<=j;k++){
                currsum+=nums[k];
                sum=max(sum,currsum);
            }
        }
    }
    return sum;
}

//O(n2) solution
int better(vector<int>& nums){
    int sum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        int currsum=0;
        for(int j=i;j<nums.size();j++){
                currsum+=nums[j];
                sum=max(sum,currsum);
        }
    }
    return sum;
}

int main(){
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(arr)<<endl;
    cout<<bruteforce(arr)<<endl;
    cout<<better(arr);
}