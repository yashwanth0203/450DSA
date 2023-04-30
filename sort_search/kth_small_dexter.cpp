/*Dexter was good in finding the K th smallest number from a set of numbers. He thought he could solve any problem related to K th smallest number. His friend Pipi challenged him with a problem.
He gave him various ranges of number, These numbers were arranged in increasing order(only distinct numbers to be taken into account). Now he asked him to find the K th smallest number in the sequence, again and again.

Input Format
The first line contains T, the number of test cases.
For each test case, there will be two integers N and Q.
Then N lines follow each line containing two integers A and B (denoting the range A-B)
Then Q lines follow each line containing a non-negative integer K .

Output Format
For each query output the K th smallest number.

Constraints
1 <= T <= 100
1 <= N <= 100
1 <= Q <= 1000
-10^18 <= A <= B <= 10^18
K >= 1

N.B. If Kth smallest number is not present in the series, print -1*/

/*The given question states that there will be t test cases given and for each test cases there will be
N and Q where N is number of different ranges and Q is the number of queries.For each test case we have
to merge different range of N intervals and give the values for K at each case.Now since the constraints
are 10^18 for A and B that is range we cant merge the arrays and sort in one array.*/

/*Lets understand appraoch.For each test case take input N and Q.Take the range as input for N times.
The range of inputs can be stored in array.Now these ranges can be sorted in ascending order.Now its 
time to merge overlapping intervals.We already know the approach take idx to be first range and i to 
be second range if end of first is greater than second then merge them.If thats not the case we can 
make idx to be i that is for example assume there are two intervals (1,7),(3,9),(8,14),(20,22).Now idx will be
at 0th range and i will be at 1st range now we will merge both of them leading to (1,9) (3,9) (8,14) (20,22).Next
iteration its compared again when i is at 2 then the merged will be (1,14) (3,9) (8,9) (20,22).In next iteration when
i is at 3 its compared 9<20 then we can increase idx since there is no overlapping.Now the result must be
(1,14) (20,22) but what we got is 4 ranges wherein two are already included in first.Hence we will
make idx values to be as i and the result would be (1,14) (20,22) (8,9) (20,22).Now only first two indices
are necessary hence while searching we use only till idx for iteration.Now lets come to searching part
initially i will be at 0th range we will check whether k is at this interval by last-first+1 the reason
being used +1 is because its inclusive.If its in that range we will declare ans as first+k-1 the reason
being -1 is when added k it goes to k+1th place so we subtract -1.If this is not the case we will
go to next iteration wherein next range is examined.*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,q;
		cin>>n>>q;
		vector<pair<ll,ll>> data(n);

        // Sorting the given ranges wrt forst arg
		for(int i=0;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			data[i]={x,y};
		}

		sort(data.begin(),data.end());

		//Merging the overlaping intervals

		int idx=0;

		for(int i=1;i<n;i++)
		{
			if(data[idx].second>=data[i].first)
			{
				data[idx].second=max(data[idx].second,data[i].second);
			}
			else
			{
				idx++;
				data[idx].second=data[i].second;
				data[idx].first=data[i].first;
			}
		}

		//Resolving the query

		while(q--)
		{
			ll k;
			cin>>k;
			ll ans=-1;
			for(int i=0;i<=idx;i++)
			{
				if((data[i].second-data[i].first+1)>=k)
				{
					ans=data[i].first+k-1;
					break;
				}
				else
				{
					k-=(data[i].second-data[i].first+1);
				}
			}
			cout<<ans<<endl;
		}


	}
	return 0;
}

/*
Binary search
You can apply BINARY SEARCH to reduce the time complexity. Just do the preprocessing as told in the video(hats of to him for clear explanation). 
Since you wanna apply binary search you have to get some sorted increasing array. Now notice to find kth element we can form a prefix array of no of elements in pairs of vector v. Lemme explain by an eg. lets say v={{1,4}, {7,9}, {10, 11}} so no of elements in pairs of v are {4, 3, 2} hence our prefix array will be{4, 4+3, 4+3+2} => pre={4, 7, 9}.
Now to get kth element we can simply find lower_bound of k in prefix array which will give us an index in which kth element will be located. Lets say we wanna find 6th smallest then lower_bound(pre, pre+n, 6) - pre = 1 (i.e. index =1) so you will have kth element in first index of vector v hence ans = v[index].first + (k - pre[index-1]) -1. we do k-pre[index-1]  as we lost some k while traversing through the array and -1 as first element v[index].first is already included. hence answer of eg= v[1] + (6-pre[0])-1= 7+(6-4)-1=8.
Now its code
#include<bits/stdc++.h>
#define int long long int
using namespace std;
inline void solve(){
    int n, q, k;
	cin>>n>>q;
	vector<pair<int, int>> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i].first>>vec[i].second;
    sort(vec.begin(), vec.end());
    int lol=0;
    for(int i=1; i<vec.size(); i++){
        if(vec[lol].second>=vec[i].first)
            vec[lol].second=max(vec[lol].second, vec[i].second);
        else{
            lol++;
            vec[lol]=vec[i];
        }
    }
    n=lol+1;
    vector<int> pre(n);
    pre[0]=vec[0].second-vec[0].first+1;
    for(int i=1; i<n; i++)
        pre[i]+= vec[i].second-vec[i].first+1+pre[i-1];
	for(int i=1; i<=q; i++){
		cin>>k;
        auto x = lower_bound(pre.begin(), pre.end(), k);
        if(x==pre.end()) // element is not in range
            cout<<"-1\n";
        else{
            int idx=x-pre.begin();
            int diff;
            if(idx==0) diff=k-1;
            else diff=k-pre[idx-1]-1;
            int ans=vec[idx].first+diff;
            cout<<ans<<"\n";
        }
	}
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t-- >0){
        solve();
    }
    return 0;
}*/