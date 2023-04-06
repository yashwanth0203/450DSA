/*Given an array of N integers, and an integer K, find the number of pairs of elements in the array
 whose sum is equal to K.*/
 /*
 The brute force approach would be two create two loops and search for all the possible combinations
  */

/*We will add all the values to map so that they can be refered in future. Now whenever we can see
the sum-current element is already present it means that the pair is found and count can be increased.
Now if the array is distinct we can make count+1.But since we assumed that elements are repeated
the total ways would be no of repeated elements so we increase the value by maps value*/
 #include <bits/stdc++.h>
 using namespace std;

 int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int rem=k-arr[i];
            if(mp[rem])
                ans+=mp[rem];
            mp[arr[i]]++;
        }
        return ans;
}

int main(){
    int arr[]={1,2,1,1};
    int k=3;
    cout<<getPairsCount(arr,4,k);
}
