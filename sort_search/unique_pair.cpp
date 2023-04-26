/*Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
*/
#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& nums, int k) {
    set<pair<int,int>>st;
    int i = 0;
    int j = 1;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    while (i < n && j < n) {
        if (i != j && abs(nums[i] - nums[j]) == k) {
            st.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (abs(nums[i] - nums[j]) > k) {
            i++;
        }
        else {
            j++;
        }
    }
    return st.size();
}


int main(){
    vector<int>arr={3,1,4,1,5};
    cout<<findPairs(arr,2);
}