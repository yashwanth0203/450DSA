/*Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth
smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2)*/

/*Use maxheap to store k elements and compute maxheaps top to get answer*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
                
            }
        }
        return pq.top();
}
/*Upper bound returns the address of the middle element which returns the address this when subtracted
with initial elements address give the number of elements satisfying condition in that row.*/
int KthSmallest(vector<vector<int>>& matrix, int k){
int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low < high){
            
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i = 0; i < n; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                
            }
            
            if(count < k){
                low = mid + 1;
            }else{
                high = mid;
            }   
        }
        return low;
}

int main(){
    vector<vector<int>>arr={{1,5,9},{10,11,13},{12,13,15}};
    cout<<kthSmallest(arr,4)<<endl;
    cout<<KthSmallest(arr,4)<<endl;
}