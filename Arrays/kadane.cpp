#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
        long long currSum=arr[0];
        long long res=arr[0];
        for(int i=1;i<n;i++){
            currSum=max((long long)arr[i],currSum+arr[i]);
            res=max(res,currSum);
        }
        return res;
    }