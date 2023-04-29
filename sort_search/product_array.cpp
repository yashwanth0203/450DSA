/*Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is
 equal to the product of all the elements of nums except nums[i].*/

/*The approach is simple . Maintain two arrays left and right for each array and multiply both of them
to obtain desired result for a given index.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n),r(n);
        l[0]=1;
        r[n-1]=1;
        for(int i=1;i<n;i++)
            l[i] = l[i-1]*nums[i-1];
        
        for(int i=n-2;i>=0;i--)
            r[i]=r[i+1]*nums[i+1];
            
        for(int i=0;i<n;i++)
            nums[i]=l[i]*r[i];
        
        return nums;
    }

int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>res=productExceptSelf(arr);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}