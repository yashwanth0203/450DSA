/*An array contains both positive and negative numbers in random order. Rearrange the array elements
 so that all negative numbers appear before all positive numbers.*/

//First approach is to take two pointers i and j and swap accordingly
#include <bits/stdc++.h>
using namespace std;
 
void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

//Two pointers
//If left and right are negative increment left
//If left is positive and right is negative swap left,right left++,right--
//If left and right is positive right--
void shiftall(int arr[], int left,
              int right)
{
   
  // Loop to iterate over the
  // array from left to the right
  while (left<=right)
  {
   if(arr[left]>=0 && arr[right]<0){
    swap(arr[left],arr[right]);
    left++;
    right--;
   }
   if(arr[left]<0)
    left++;
   if(arr[right]>=0)
    right--;
  }
}

//Dutch Flag
//ar[1…low-1] negative integers
//ar[low…high] unknown
//ar[high+1…N] positive integers

void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}

//Rearranging preserving the order
//Whenever we encounter a negative from right end,shift all elements of left by one and then insert value
//This approach doesnt work if first element is negative
void rearrange(int arr[],int n){
    for(int i=0;i<n;i++){
        int temp=arr[i];
        if(temp<0){
            int j=i-1;
            while(j>=0 &&arr[j]>=0){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
    }
}

//Preserving order but extra space
void segregateElements(int arr[],int n)
    {
        int a[n];
       int k =0;
       for(int i = 0; i< n ; i++){
           if(arr[i] > 0){
               a[k] = arr[i];
               k++;
           }
       }
       for(int i = 0; i< n; i++){
           if(arr[i]< 0){
               a[k] = arr[i];
               k++; 
           }
       }
       for(int i = 0; i< n; i++){
           arr[i] = a[i];
       }
    }