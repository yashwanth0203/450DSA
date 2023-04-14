/*Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.*/

/*We first transpose the given matrix, and then reverse the content of individual rows to get the
 resultant 90 degree clockwise rotated matrix.*/

//For more approaches visit gfg

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
//CODE HERE 
    int m=matrix.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<m;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    vector<vector<int>>arr={{1,2,3},
    {4,5,6},
    {7,8,9}};
    rotate(arr);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}