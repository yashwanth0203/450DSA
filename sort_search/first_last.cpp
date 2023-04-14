/*Given a sorted array arr containing n elements with possibly duplicate elements, the task is to
 find indexes of first and last occurrences of an element x in the given array.It is given that
 we need to find first and last occurences of element so we can use the binary search.But the twist
 is that there are duplicates in the array so we should not stop searching in case of finding if we find 
 mid we need to made high=mid-1 and in case of right index we need to make low=mid+1.By this method
 we can find extreme indices of the number*/

#include<bits/stdc++.h>
using namespace std;

int leftSearch(int arr[], int low, int high, int key)
{
    int ind= -1;
    while(low <= high)
    {
        int mid= low+ ((high-low)>>1);
        if(arr[mid] == key)
        {
            ind= mid;
            high = mid-1;
        }
        else if(arr[mid] > key)
        {
            high = mid-1;
        }
        else low= mid+1;
    }
    return ind;
}

int rightSearch(int arr[], int low, int high, int key)
{
    int ind= -1;
    while(low <= high)
    {
        int mid= low+ ((high-low)>>1);
        if(arr[mid] == key)
        {
            ind= mid;
            low =mid+1;
        }
        else if(arr[mid] > key)
        {
            high = mid-1;
        }
        else low= mid+1;
    }
    return ind;
}

vector<int> find(int arr[], int n , int x )
{
    int left= leftSearch(arr,0,n-1,x);
    if(left== -1) return {-1,-1};
    int right= rightSearch(arr, 0, n-1, x);
    return {left, right};
}

int main(){
    int arr[]={1,2,2,3,3,4,5};
    vector<int>ans=find(arr,7,3);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}