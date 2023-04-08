/*Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums
 up to the given integer X.*/

#include <bits/stdc++.h>
using namespace std;

/*The approach is simple we take the current element as one element of triplet and use two pointer 
approach.The first pointer starts from immediate next element and second pointer starts from last element
We iterate only till last third element because we need atleast three elements to form a triplet sum.*/
bool find3Numbers(int A[], int n, int X)
    {
        int l, r;
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++) {
        l = i + 1; 
        r = n - 1;
        while (l < r) {
            if (A[i] + A[l] + A[r] == X) {
                return true;
            }
            else if (A[i] + A[l] + A[r] < X)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    return false;
    }

int main(){
    int arr[]={1,4,45,6,10,8};
    cout<<find3Numbers(arr,6,13);
}