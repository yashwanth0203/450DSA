/*You are given a 0-indexed integer array nums of even length consisting of an equal number of positive
and negative integers.You should rearrange the elements of nums such that the modified array follows the
given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr) {
        vector<int>positive;
        vector<int> negative;
        int n=arr.size();
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            negative.push_back(arr[i]);
        else
            positive.push_back(arr[i]);
    }
    int j = 0, i = 0;
    for (k = 0; k < n && i < positive.size() && j < negative.size(); k++) {
        if (k % 2 == 0)
            arr[k] = positive[i++];
        else
            arr[k] = negative[j++];
    }
    while (i < positive.size() && k < n)
        arr[k++] = positive[i++];
    while (j < negative.size() && k < n)
        arr[k++] = negative[j++];
    return arr;
    }