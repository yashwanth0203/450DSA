/*Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates
 in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to
distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates
   given to a student is minimum.*/

/*The approach is to find the minimum difference between two elements such that their distance is m.
To do that we have to sort the array*/

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long res=INT_MAX;
    for(long long i=0;i<n-m+1;i++)
        res=(long long)min(a[i+m-1]-a[i],res);
    return res;
}

int main(){
    vector<long long>arr={3, 4, 1, 9, 56, 7, 9, 12};
    cout<<findMinDiff(arr,8,5);
}