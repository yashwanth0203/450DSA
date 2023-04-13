/*Given an NxN matrix Mat. Sort all elements of the matrix.*/

#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int>v;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
               v.push_back(Mat[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int x=0;
         for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
              Mat[i][j]=v[x];
              x++;
                
                
            }
         }
        return Mat;
}

int main(){
    vector<vector<int>>arr={{10,20,30,40},
{15,25,35,45}, 
{27,29,37,48}, 
{32,33,39,50}};
arr=sortedMatrix(4,arr);
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        cout<<arr[i][j]<<" ";
    cout<<endl;
}

}