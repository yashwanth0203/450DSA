/*Given two arrays a[] and b[] of size n and m respectively. The task is to find the number of elements
 in the union between these two arrays.*/

 //Using set
#include<bits/stdc++.h>
using namespace std;
int doUnion(int a[], int n, int b[], int m)  {
        set<int>s;
        for(int i=0;i<n;i++)
            s.insert(a[i]);
        for(int i=0;i<m;i++)
            s.insert(b[i]);
        return s.size();
}

//Using hashmap
int doUnion1(int a[], int n, int b[], int m)  {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(int i=0;i<m;i++){
            mp[b[i]]++;
        }
        return mp.size();
    }

int main(){
    int arr1[]={0,1,0,2,0,1,2};
    int arr2[]={0,1,0,2,0,1,2,3};
    cout<<doUnion(arr1,7,arr2,8)<<endl;
    cout<<doUnion1(arr1,7,arr2,8)<<endl;
}