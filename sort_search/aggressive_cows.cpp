// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//See techdose for explanation
int main() {
	
		int a[]={1,2,4,8,9};
		int n=5;
		int c=3;
		sort(a,a+n);
		int low=0;
		int high=a[n-1];
		int mid,best=0;
		while(low<=high){
			mid=low+(high-low)/2;
			int cnt=1,left=0;
			for(int i=1;i<n && cnt<c;i++){
				if(a[i]-a[left]>=mid){
					left=i;
					cnt++;
				}
			}
			if(cnt>=c){
				low=mid+1;
				best=mid;
			}
			else
				high=mid-1;
		}
		cout<<best<<endl;
	
	
}