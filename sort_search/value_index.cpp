/*Given an array Arr of N positive integers. Your task is to find the elements whose value is equal to that of its index value ( Consider 1-based indexing )*/

#include <bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int>res;
	    for(int i=0;i<n;i++){
	        if(arr[i]==i+1)
	            res.push_back(i+1);
	    }
	    return res;
}

int main(){
    int arr[]={15, 2, 45, 12, 7};
    vector<int>res=valueEqualToIndex(arr,5);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}