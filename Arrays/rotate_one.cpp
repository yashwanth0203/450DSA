/*Given an array, rotate the array by one position in clock-wise direction.*/

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=temp;
}

int main(){
    int arr[]={2,3,4,5,1};
    rotate(arr,5);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
}