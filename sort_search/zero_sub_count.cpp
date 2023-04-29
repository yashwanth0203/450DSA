/*You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.*/

#include <bits/stdc++.h>
using namespace std;

/*The approach is very simple:-

calculate the prefixSum for every element
now check how many times the particular prefixSum is repeat (let's say x times repeat), then our answer
 is the summation of whole these (x*(x-1))/2
example      {0,0,5, 5,  0,  0}
prefix sum = 0 0 5 10 10 10
particular prefixSum                   it's cnt / repeatition (x)
                   0                                                         2
                   5                                                         1
                  10                                                        3
answer = ( (2*1)/2 + (1*0)/2 +(3*2)/2 )
   for =>    0(x = 2)    5(x = 1)   10(x = 3)
hence answer = 1 + 0 + 3 = 4
But wait we should also have to add 2 in our answer, as that's the special conditions which we've to
 always remembered that how many times we get 0 in our prefixSum==> so 0 count is 2
Hence our final answer will be,
Answer = 4 + 2 = 6*/
long long int findSubarray(vector<long long int> &arr, int n ) {
        long long ans=0, zero=0, presum=0;

        unordered_map<long long, long long>mpp;

        for(int i=0;i<n;i++){

            presum+=arr[i];
            if(presum==0) ans++;
            mpp[presum]++;

        }

        for(auto it:mpp) {

            long long x=it.second;
            ans+= (x*(x-1))/2;

        }
        return ans;
    }

long long int findSubarray2(vector<long long int> &arr, int n ){
    unordered_map<long long,int>mp;
    long long sum=0;
    long long ans=0;
    mp[0]=1;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(mp.find(sum)!=mp.end())
            ans+=mp[sum];
        mp[sum]++;
    }
    return ans;
}

int main(){
    vector<long long int>arr={6,-1,-3,4,-2,2,4,6,-12,-7};
    cout<<findSubarray(arr,10)<<endl;
    cout<<findSubarray2(arr,10);
}