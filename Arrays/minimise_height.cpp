/*Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers
after you have modified each tower.*/

#include <bits/stdc++.h>
using namespace std;

/*Initially we sort the array,so the maximum difference would be between first and last elements.
But since its compulsory to either increase or decrease the elements the maximum and minimum could
change.Hence we need to keep track of max and min and compare with diff of last and first element.
We also need to consider element when subtracted becomes less than zero must not be altered.We try increasing
and decreasing all the elements and result is computed.*/

int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int mini,maxi;
        int res=arr[n-1]-arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i]-k<0)continue;
            maxi=max(arr[n-1]-k,arr[i-1]+k);
            mini=min(arr[0]+k,arr[i]-k);
            res=min(res,maxi-mini);
        }
        return res;
    }

int main(){
    int arr[]={1, 5, 8, 10};
    cout<<getMinDiff(arr,4,2);
}