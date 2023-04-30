/*Given an array of n distinct elements. Find the minimum number of swaps required to sort the array
in strictly increasing order*/

/*The approach is to first sort the array and then compare to original array.If there is a difference
swap the array until it matches original one.To achieve this we take a vector of pairs and sort
it based on the array value.Next comapare the index with original index if it differs swap but the 
challenge is after swapping once the loop moves forward though the index is not equal to original
instead of swapping again.To achieve this whenever there is a difference we decrease the i value
so that we can check the difference again.*/
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums){
	vector<pair<int,int>>v;
	for(int i=0;i<nums.size();i++){
	    v.push_back({nums[i],i});
	}
	sort(v.begin(),v.end());
	    
	int swaps=0;
	for(int i=0;i<nums.size();i++){
	    pair<int,int>p=v[i];
	    int value=p.first;
	    int index=p.second;
	        
	    if(i!=index){
	        swaps++;
	        swap(v[i],v[index]);
	        i--;
	    }
	}
	return swaps;
}

int main(){
    vector<int>arr={4,5,3,1};
    cout<<minSwaps(arr);
}