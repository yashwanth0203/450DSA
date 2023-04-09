/*Given an array arr of n positive integers and a number k. One can apply a swap operation on the array
any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the
minimum number of swaps required to bring all the numbers less than or equal to k together, i.e.
make them a contiguous subarray.*/

/*We have to make the minimum number of swaps so that all the elements less than k are together.We have to 
count the number of elements which is less than or equal to given k.So the subarray of size k must be present
with all elements less than or equal to k.Now among the subarrays of size k we need to know which subarray
needs minimum number of swaps that means in each subarray we need to know number of elements which are greater
than k.The number of elements greater than k is the number of swaps.So initially we make note of bad till
count.Now first subarray is computed ,make a loop from 2nd subarray start with 2md element now when left
pointer is moved right to form next subarray we need to check whether previous element was bad that is gr
eater than k if it is then decrement k now when there is new right pointer in new subarray.We should check
if this is greater than k if yes then increase bad .Traverse for all the subarrays and compute minimum
swaps required i.e,swaps required for each array*/
#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k) {
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k)
                count++;
        }
        int bad=0;
        for(int i=0;i<count;i++){
            if(arr[i]>k)
                bad++;
        }
        int ans=bad;
        for(int i=1,j=count;j<n;i++,j++){
            if(arr[i-1]>k)
                bad--;
            if(arr[j]>k)
                bad++;
            ans=min(ans,bad);
        }
        return ans;
}

int main(){
    int arr[]={2, 1, 5, 6, 3};
    cout<<minSwap(arr,5,3);
}
