#include <bits/stdc++.h>
using namespace std;
/*For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.*/
long long merge(long long arr[], long long temp[] , long long start , long long mid, long long end){
        long long inv_count = 0;
        long long i , j , k;
        i = start;
        j = mid;
        k = start;
        
        while((i <= mid-1) && (j <= end)){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
                inv_count += (mid-i);
            }
        }
        while(i <= mid-1){
            temp[k++] = arr[i++];
        }
        while(j <= end){
            temp[k++] = arr[j++];
        }
        for(i = start ; i <= end ; i++)
            arr[i] = temp[i];
        return inv_count;
    }
    
    
    long long mergeSortInv(long long arr[] , long long temp[] , long long start , long long end){
        long long inv_count = 0;
        
        if(start < end){
            long long mid = (end-start)/2 + start;
            
            inv_count += mergeSortInv(arr,temp,start,mid);
            inv_count += mergeSortInv(arr,temp,mid+1,end);
            
            inv_count += merge(arr,temp,start,mid+1,end);
        }
        return inv_count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        mergeSortInv(arr,temp,0,N-1);
    }