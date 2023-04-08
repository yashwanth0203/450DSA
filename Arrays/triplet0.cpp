/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j,
 i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/

/*The approach is same as 3sum except we use set to avoid duplicates and then convert it into vector of
triplets.But the sum is 0 thats all.*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& A) {
        int n=A.size();
        sort(A.begin(),A.end());
    set<vector<int>> triplets; // set to store unique triplets
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = A[i] + A[l] + A[r];
            if (sum == 0) {
                triplets.insert({A[i], A[l], A[r]});
                l++;
                r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    return vector<vector<int>>(triplets.begin(), triplets.end());
}

int main(){
    vector<int>arr={-1,0,1,2,-1,-4};
    vector<vector<int>>res=threeSum(arr);
    for(auto it:res){
        for(auto val:it){
            cout<<val<<" ";
        }
        cout<<endl;
}
}