/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element
 in the result must be unique and you may return the result in any order.*/
#include <bits/stdc++.h>
using namespace std;

//Efficient approach
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]>0)
                continue;
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]>0){
                res.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return res;
    }

//O(n2) efficiency
vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(auto i : nums1){
            if(count(nums2.begin(),nums2.end(),i)>0){//checks if the number present in "nums1" is also present in "nums2" 
                if(count(result.begin(),result.end(),i)==0){//checks if the number present in both "nums1" and "nums2" is already in "result" vector or not
                result.push_back(i);
                }
            }
        }
        return result;
    }
int main(){
    vector<int>arr1={1,2,3,4,5};
    vector<int>arr2={1,2,3};
    vector<int>res=intersection(arr1,arr2);
    vector<int>res1=intersection1(arr1,arr2);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
    for(int i=0;i<res1.size();i++)
        cout<<res1[i]<<" ";
    return 0;
}