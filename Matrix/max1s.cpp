/*Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the
first row that has the maximum number of 1's.*/

/*Given that array is sorted rowwise.At the best case 1 will be always at right end.We need to find
that row whose left end has 1 compareed to other rows' left ends.So we start iterating from last column
for each row if there is 0 we go to next row of same column and max row and hence max row can be computed
Since we iterate through n rows and each column is traversed only once it takes (n+m) time.*/
#include <bits/stdc++.h>
using namespace std;
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int j,max_row=-1;
	    j=m-1;
	    
	    for(int i=0;i<n;i++){
	        bool flag=false;
	        
	        while(j>=0 && arr[i][j]==1){
	            j=j-1;
	            flag=true;
	        }
	        if(flag){
	            max_row=i;
	        }
	    }
	    
	   return max_row;
	}

int main(){
    vector<vector<int>>arr={{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}};
        cout<<rowWithMax1s(arr,4,4);
}
