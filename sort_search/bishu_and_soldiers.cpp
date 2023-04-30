/*Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds
to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers
whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the 
previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak 
in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum 
of their powers.*/

/*The first line of the input contains N, the number of soldiers.
The second line contains an array of N numbers denoting the power of each soldier
This third line contains Q, which denotes the number of rounds.
Q lines follow, each line having one number denoting the power of Bishu.*/

/*For each round, the output should be an array of two numbers. The first number should be the number of 
soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers 
that Bishu can beat.*/

/*We can understand the approach by now. In each round we need to find the number of soldiers whose
power is less than bishu's and the cumulative strength of all of them. We can use linear search or
binary search lets do binary search.But here comes the twist.In binary search search instead of
finding the key that is bishu strength but we are not always sure whether we would find the exact value
therefore we need to find no of soldiers whose strength is less than or equal to that of bishu.In this
way we can get the no of soldiers.*/

/*If the value at index "mid" in the array is less than or equal to "bishu", it sets the "index" variable
to "mid" (because "mid" is a potential candidate for the index we are looking for) and updates the "start"
variable to "mid + 1" (because we know that all the elements before "mid" are less than or equal to 
"bishu", so we can safely exclude them from the search).
If the value at index "mid" in the array is greater than "bishu", it updates the "end" variable to 
"mid - 1" (because we know that all the elements after "mid" are greater than "bishu", so we can safely 
exclude them from the search).*/

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
    cout<<"Enter the number of soldiers"<<endl;
	cin>>n;
	vector<int>v(n),prefix(n);
    cout<<"Enter the soldiers strength"<<endl;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
		prefix[i]=(i>0?prefix[i-1]+v[i]:v[i]);
    cout<<"Enter the number of rounds"<<endl;
	cin>>q;
	for(int i=0;i<q;i++){
		int bishu,start=0,index=0,end=n-1;
        cout<<"Enter the bishu strength"<<endl;
		cin>>bishu;
		while(start<=end) {
			int mid=(start+(end-start)/2);
			if(v[mid]<=bishu) {
				index=mid;
				start=mid+1;
			}
			else {
				end=mid-1;
			}
		}
		cout<<index+1<<" "<<prefix[index]<<endl;
	}
}