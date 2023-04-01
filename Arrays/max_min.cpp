/*Given an array of size N. The task is to find the maximum and the minimum element of the array
 using the minimum number of comparisons.*/

 #include <bits/stdc++.h>
 using namespace std;


//O(n) approach
void min_max(int arr[],pair<int,int> &p,int n){
        int min=INT_MAX;
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max)max=arr[i];
            if(arr[i]<min)min=arr[i];
        }
        p.first=max;
        p.second=min;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    pair<int,int>p;
    min_max(arr,p,n);
    cout<<p.first<<" "<<p.second;
}

//O(logn) approach

pair<int,int> min_max(int arr[],int low,int high){
        pair<int,int> p,left,right;
        if(low==high){
            p.first=arr[low];
            p.second=arr[low];
            return p;
        }
        if(high==low+1){
            if(arr[low]>arr[high]){
                p.first=arr[high];
                p.second=arr[low];
            }
            else{
                p.first=arr[low];
                p.second=arr[high];
            }
            return p;
        }
        int mid=(low+high)/2;
        left=min_max(arr,low,mid);
        right=min_max(arr,mid+1,high);

        // Compare minimums of two parts
    if (left.first < right.first)
        p.first = left.first;
    else
        p.first = right.first;
  
    // Compare maximums of two parts
    if (left.second > right.second)
        p.second = left.second;
    else
        p.second = right.second;
  
 return p;
}

int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    pair<int,int>p=min_max(arr,0,n-1);
    cout<<"Min: "<<p.first<<" Max: "<<p.second;
}

//This approach iterates half times
//We will compare the numbers in pairs
void min_max(int arr[],pair<int,int> &p,int n){
    int i=0;
        if(n%2==0){
            if(arr[0]>arr[1]){
                p.first=arr[1];
                p.second=arr[0];
            }
            else{
                p.first=arr[0];
                p.second=arr[1];
            }
         i=2;
        }
        else{
            p.first=arr[0];
            p.second=arr[0];
        }
        for(int i=2;i<n;i+=2){
          if(arr[i]>arr[i+1]){
            if(arr[i]>p.second)
                p.second=arr[i];
            if(arr[i+1]<p.first)
                p.second=arr[i+1];
          }
          else{
            if(arr[i]<p.first)
                p.first=arr[i];
            if(arr[i+1]>p.second)
                p.second=arr[i+1];
          }
        }
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    pair<int,int>p;
    min_max(arr,p,n);
    cout<<"Min: "<<p.first<<" Max: "<<p.second;
}