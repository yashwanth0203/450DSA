/*Given a matrix of size r*c. Traverse the matrix in spiral form.*/
/*Take four variables Top,Bottom,Left,Right.We take four directions 1,2,3,4.First direction will be from
left to right including the end element.Second direction will be from top(below end) to bottom(includeing
last column).Third direction will be from right(last column-1) to left(including bottom) and fourth 
direction will be from bottom to top.After first direction Top will be increased since that rows 
elements are filled.For second direction we decrease right since columns are filled.The third direction
bottom roms are being pushed so bottom goes up(bottom--) and for fourth direction left++ since the
elements of left column elements are being pushed.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(int matrix[][4], int r, int c) 
    {
        int T,L,B,R,dir;
        T=0;
        B=r-1;
        L=0;
        R=c-1;
        dir=0;
        vector<int>ans;
        while(T<=B && L<=R){
            if(dir==0){
                for(int i=L;i<=R;i++)
                    ans.push_back(matrix[T][i]);
                T++;
            }
            else if(dir==1){
                for(int i=T;i<=B;i++)
                    ans.push_back(matrix[i][R]);
                R--;
            }
            else if(dir==2){
                for(int i=R;i>=L;i--)
                    ans.push_back(matrix[B][i]);
                B--;
            }
            else if(dir==3){
                for(int i=B;i>=T;i--)
                    ans.push_back(matrix[i][L]);
                L++;
            }
            dir=(dir+1)%4;
        }
        return ans;
}

int main(){
    int matrix[][4]={{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}};
    vector<int>res=spirallyTraverse(matrix,4,4);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    
}
