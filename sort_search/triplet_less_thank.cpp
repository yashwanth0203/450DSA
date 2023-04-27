/*Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of
triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given
value sum.*/

/*Remember for these kind of questions its better to use pointers approach for which we need to sort
the array. As usually take two pointers i and j and another pointer k which is at end. Now when the
sum at these points is less than sum we know that this applies to all elements after j and before k
hence we increase count by that amount and then increase j for next iteration,in this way we can find
the number of triplets less than k.*/
#include <bits/stdc++.h>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n);
    long long count = 0;
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            if (arr[i] + arr[j] + arr[k] >= sum) {
                k--;
            } else {
                count += (k - j);
                j++;
            }
        }
    }
    return count;
}

int main(){
    long long arr[]={-2, 0, 1, 3};
    cout<<countTriplets(arr,4,2);
}