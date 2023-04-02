/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
 of the same color are adjacent, with the colors in the order red, white, and blue.We will use the
  integers 0, 1, and 2 to represent the color red, white, and blue, respectively*/

#include <bits/stdc++.h>
using namespace std;

//Naive approach would be use sorting algorithm O(nlogn)

//This approach makes use of hashmap.
void sortColors(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int i=0;
        while(mp[0]!=0){
            nums[i]=0;
            i++;
            mp[0]--;
        }
        while(mp[1]!=0){
            nums[i]=1;
            i++;
            mp[1]--;
        }
        while(mp[2]!=0){
            nums[i]=2;
            i++;
            mp[2]--;
        }
    }


//Most efficient Dutch National Flag Algorithm
//0 to low-1->0
//low to mid-1->1
//mid to high->unsorted
//high+1 to n-1->2
/*Since initially entire array is unsorted we point index 0 to mid and index n-1 to high
Low is also at index 0.If 0 is at mid we need to put it after low-1 i.e,low hence 0 to low would be 0,
but 0 must be till low-1 not low hence we do low++.Hence if mid is 0 swap mid,low and low++.Now if mid
is 1 it must be till mid-1 but now its at mid so we will do mid++. Now if we have 2,it must be b/w high+1
to n-1 so we insert it before high+1  i.e,high to make 2 lie b/w high+1 to n-1 we make high-- We swap mid and high before this*/

void DutchFlag(vector<int>& nums){
    int left=0;
    int mid=0;
    int right=nums.size()-1;
    for(int i=0;i<nums.size();i++){
        if(nums[mid]==0){
            swap(nums[mid],nums[left]);
            mid++;
            left++;
        }
        else if(nums[mid]==1)
            mid++;
        else{
            swap(nums[mid],nums[right]);
            right--;
        }
    }
}
int main(){
    vector<int>arr={0,1,0,2,0,1,2};
    DutchFlag(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}