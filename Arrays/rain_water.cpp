/*Given an array arr[] of N non-negative integers representing the height of blocks. If width of each
 block is 1, compute how much water can be trapped between the blocks during the rainy season. */

#include <bits/stdc++.h>
using namespace std;

/*We maintain two arrays which store left max and right max.But we need to take care of height too.So
we subtract the height from min of leftmax and right max the reason for choosing minimum being
water occupies till minimum rest of the water overflows.*/
long long trappingWater(int arr[], int n){
        if(n<=2)
            return 0;
        vector<int>left_max(n,0);
        vector<int>right_max(n,0);
        left_max[0]=arr[0];
        right_max[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++)
        {
        left_max[i]=max(left_max[i-1],arr[i]);
        right_max[n-i-1]=max(right_max[n-i],arr[n-i-1]);
        }
        long long water=0;
        for(int i=0;i<n;i++)
            water+=min((long long)left_max[i],(long long)right_max[i])-(long long)arr[i];
        return water;
    }

int main(){
    int arr[]={3,0,0,2,0,4};
    cout<<(int)trappingWater(arr,6);
}