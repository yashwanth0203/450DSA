/*Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.*/
#include <bits/stdc++.h>
using namespace std;


//Using inbuilt sort O(nlogn)
int sort(vector<int> &nums,int k){
    sort(nums.begin(),nums.end(),greater<int>());
    return nums[k-1];
}

int max_heap(vector<int> &nums,int k){
    priority_queue<int>max_heap;
        if(k>nums.size())return -1;
        for(int i=0;i<nums.size();i++)
            max_heap.push(nums[i]);
        
        for(int i=1;i<k;i++){
            max_heap.pop();
        }
        return max_heap.top();
}

int min_heap(vector<int> &nums,int k){
    priority_queue<int,vector<int>,greater<int>>min_heap;
    for(int i=0;i<nums.size();i++){
        if(min_heap.size()<k)
            min_heap.push(nums[i]);
        else{
            if(min_heap.top()<nums[i]){
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
    }
    return min_heap.top();
}

int main(){
    vector<int>arr={1,2,3,4};
    cout<<sort(arr,2)<<endl;
    cout<<max_heap(arr,2)<<endl;
    cout<<min_heap(arr,2)<<endl;
}