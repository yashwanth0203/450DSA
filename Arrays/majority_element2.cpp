/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

/*In the majority element 1 approach we assumed that always there will be a majority element.
But its not always true to verify that we can run other loop and look at if candidate count>n/2.
In this problem we can understand that there can be atmost 2 elements which can repeat more than
n/3 times.So we will take two candidates and two lives and everything is same as the majority element.
But the difference we are not always sure of getting 2 elements so we keep track of count1 and count2
and if they are greater than n/3 we push them into the vector.This is Moore Voting ALgorithm.This is
explained excellently by Code with Alisha Youtube channel.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        int candidate1=INT_MIN;
        int candidate2=INT_MIN;
        int life1=0;
        int life2=0;
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1)
                life1++;
            else if(nums[i]==candidate2)
                life2++;
            else if(life1==0){
                candidate1=nums[i];
                life1=1;
            }
            else if(life2==0){
                candidate2=nums[i];
                life2=1;
            }
            else{ 
                life1--;
                life2--;
            }
        }
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1)count1++;
            if(nums[i]==candidate2)count2++;
        }
        if(count1>n/3)res.push_back(candidate1);
        if(count2>n/3)res.push_back(candidate2);
        
        return res;
}

int main(){
    vector<int>arr={3,2,3};
    vector<int>res=majorityElement(arr);
    for(int i=0;i<res.size();i++)
        cout<<res[i];
}