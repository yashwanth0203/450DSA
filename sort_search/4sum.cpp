/*Given an array of integers and another number. Find all the unique quadruple from the given array 
that sums up to the given number.*/

#include <bits/stdc++.h>
using namespace std;

/*The naive approach is to use four for loops*/

void naive(vector<int>&nums,int target){
    int n=nums.size();
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                for(int l=k+1;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                        cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<nums[l]<<endl;
                }
            }
        }
    }
}


/*The next approach uses three loops here there are two loops using pointers i and j.But before that we
need to sort the array so that two pointer approach can be used.We will take the sum of elements in i and
j and we need to find remaining pointers sum which is low and high where low is j+1 and high is n-1
if the pointer sum is equal we can add that if its less increase low else decrease greater.This should 
be continued until low is less than high.Then in the next iteration j increases.Again to avoid duplicates
we need to check with previous element at each iteration if true then continue.In this way we can find
the sum of four elements.*/


        vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i< n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n-2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                long long tSum=(long long)target - (long long)nums[i] - (long long)nums[j];
                int l = j + 1, h = n - 1;
                while (l < h){
                    if (nums[l] + nums[h] == tSum){
                        vector<int> oneAns = {nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(oneAns);
                        while(l < h && nums[l] == nums[l + 1]){
                            l++;
                        }
                        while(l < h && nums[h] == nums[h - 1]){
                            h--;
                        }
                        l++;
                        h--;
                    }
                    else if(nums[l] + nums[h] < tSum){
                        l++;
                    }
                    else{
                        h--;
                    }   
                }       
            }
        }
        return ans;
    }

int main(){
    vector<int>arr={10,2,3,4,5,7,8};
    naive(arr,23);

}