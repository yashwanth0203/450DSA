/*Given an array of size N. The task is to find the maximum and the minimum element of the array using
 the minimum number of comparisons.*/

/*First approach is to sort*/

#include<bits/stdc++.h>
using namespace std;
 
pair<int,int> sortMinMax(int arr[], int n)
{
    pair<int,int>minmax;
 
    sort(arr, arr + n);
 
    minmax.first = arr[0];
    minmax.second = arr[n - 1];
 
    return minmax;
}

/*This approach uses linear search*/
pair<int,int> linearMinMax(int arr[], int n)
{
    pair<int,int>minmax;    
    int i;
  
    if (n == 1)
    {
        minmax.first = arr[0];
        minmax.second = arr[0];    
        return minmax;
    }
 
    if (arr[0] > arr[1])
    {
        minmax.first = arr[1];
        minmax.second = arr[0];
    }
    else
    {
        minmax.first = arr[0];
        minmax.second = arr[1];
    }
     
    for(i = 2; i < n; i++)
    {
        if (arr[i] > minmax.second)    
            minmax.second = arr[i];
             
        else if (arr[i] < minmax.first)    
            minmax.first = arr[i];
    }
    return minmax;
}

/*Use divide and conquer method to find max and min by comparing two arrays*/

pair<int,int> divideMinMax(int arr[], int low, int high)
{
    pair<int,int> minmax, mml, mmr;
    int mid;
 
    // If there is only one element
    if (low == high) {
        minmax.second = arr[low];
        minmax.first = arr[low];
        return minmax;
    }
 
    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.second = arr[low];
            minmax.first = arr[high];
        }
        else {
            minmax.second = arr[high];
            minmax.first = arr[low];
        }
        return minmax;
    }
 
    // If there are more than 2 elements
    mid = (low + high) / 2;
    mml = divideMinMax(arr, low, mid);
    mmr = divideMinMax(arr, mid + 1, high);
 
    // Compare minimums of two parts
    if (mml.first < mmr.first)
        minmax.first = mml.first;
    else
        minmax.first = mmr.first;
 
    // Compare maximums of two parts
    if (mml.second > mmr.second)
        minmax.second = mml.second;
    else
        minmax.second = mmr.second;
    return minmax;
}

/*Maximum and minimum of an array by comparing in pairs:
If n is odd then initialize min and max as the first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For the rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. */

pair<int,int> pairMinMax(int arr[], int n)
{
    pair<int,int>minmax;    
    int i;
     
    // If array has even number of elements
    // then initialize the first two elements
    // as minimum and maximum
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])    
        {
            minmax.second = arr[0];
            minmax.first = arr[1];
        }
        else
        {
            minmax.first = arr[0];
            minmax.second = arr[1];
        }
        i = 2;
    }
    else
    {
        minmax.first = arr[0];
        minmax.second = arr[0];
         
        // Set the starting index for loop
        i = 1;
    }
     
    // In the while loop, pick elements in
    // pair and compare the pair with max
    // and min so far
    while (i < n - 1)
    {        
        if (arr[i] > arr[i + 1])        
        {
            if(arr[i] > minmax.second)    
                minmax.second = arr[i];
                 
            if(arr[i + 1] < minmax.first)        
                minmax.first = arr[i + 1];    
        }
        else       
        {
            if (arr[i + 1] > minmax.second)    
                minmax.second = arr[i + 1];
                 
            if (arr[i] < minmax.first)        
                minmax.first = arr[i];    
        }
        i += 2;
    }        
    return minmax;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    pair<int,int>res1=sortMinMax(arr,6);
    pair<int,int>res2=linearMinMax(arr,6);
    pair<int,int>res3=divideMinMax(arr,0,5);
    pair<int,int>res4=pairMinMax(arr,6);
    cout<<res1.first<<" "<<res1.second<<endl;
    cout<<res2.first<<" "<<res2.second<<endl;
    cout<<res3.first<<" "<<res3.second<<endl;
    cout<<res4.first<<" "<<res4.second<<endl;
}