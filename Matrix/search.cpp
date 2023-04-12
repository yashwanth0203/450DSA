/*You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(!matrix.size()){
            return false;
        }
        
        int n=matrix.size(); //rows
        int m=matrix[0].size(); //cols
        
        int lo=0;
        int h= (n*m)-1;
        
        while(lo<=h){
            
            
            int mid= (lo +(h-lo)/2);
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            
            else if(matrix[mid/m][mid%m] < target){
                lo=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
}

int main(){
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(matrix,0);
}