//Given an array (or string), the task is to reverse the array/string.

#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[],int n){
    int i=0;
    while(i<n){
        int temp=arr[i];
        arr[i]=arr[n];
        arr[n]=temp;
        i++;
        n--;
    }
}

int  main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
