/*A step array is an array of integers where each element has a difference of at most k with its
 neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return
  the first occurrence of the key.*/


/*The naive approach is simple we need to do linear search.This can be optimised by using the property
that elements are at atmost k difference. It means no need to iterate every element since we know
that atmost there is k difference we would consider the worst case and could estimate how far the
element could be. This can be done by estimating no of steps which is calculated by difference divided
by k which gives the index from which we can start the search.*/
#include <bits/stdc++.h>
using namespace std;

void search(vector<int>&arr,int n,int key,int k){
    int i=0;
    while(i<n){
        if(arr[i]==key){
            cout<<i<<endl;
            break;
        }
        else
            i=i+max(1,abs(arr[i]-key)/k);
    }
}

int main(){
    vector<int>arr={1,3,4,5,6};
    int k=2;
    int key=5;
    search(arr,5,5,2);
}