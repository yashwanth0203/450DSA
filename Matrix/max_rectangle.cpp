/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing
 only 1's and return its area.*/

/*To understand this we need to first understand about maximum histogram area.In the histogram for
finding maximum area the complete length of atleast one bar for one of the areas is included it
means that for any area there is atleast one bar whose complete height is included.Now since we have
to find the area wrt to this bar we need to understand that the bars which are below its height cant
be included in the area. Hence we need to keep track of two vectors left and right so that we can ca
lculate area between only these bars and this process is repeated for all bars and all areas are com
puted for all the bars and the maximum area canbe obtained.Now for 2d array we can assume each row
as an histogram and compute area next iteration if below row has 1 then we need to add above
row value to compute area.however if we encounter zero we need to write it as 0.So we need to find
maximum histogram area for each row and return the maximum area.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> heights){
        int n=heights.size();
        vector<int> left(n);
        stack<int> mystack;
        for(int i=0;i<n;i++){
            if(mystack.empty()){
                left[i]=0;
                mystack.push(i);
            }
        else{
        while(!mystack.empty() && heights[mystack.top()]>=heights[i]){
            mystack.pop();
                }
        left[i]=mystack.empty()?0:mystack.top()+1;
        mystack.push(i);
            }
        }
        return left;
    }
    vector<int> NSR(vector<int> heights){  // Function to find indices of next smallest right element
        int n=heights.size();
        vector<int> right(n);
        stack<int> mystack;
        for(int i=n-1;i>=0;i--){
            if(mystack.empty()){
                right[i]=n-1;
                mystack.push(i);
            }
        else{
        while(!mystack.empty() && heights[mystack.top()]>=heights[i]){
            mystack.pop();
                }
        right[i]=mystack.empty()?n-1:mystack.top()-1;
        mystack.push(i);
            }
        }
        return right;
    }
    int MAH(vector<int>& heights) {  //Function to find maximum area of histogram
        vector<int> right;
        vector<int> left;
        
        right = NSR(heights);
        left = NSL(heights);
        
        int mx = 0;
        
        for(int i=0;i<heights.size();i++){
            mx=max(mx,(right[i]-left[i]+1)*heights[i]);
        }
        
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n == 0) return 0;
        
        int m=matrix[0].size();
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(matrix[0][j]-'0');
        }
        int mx = MAH(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                    v[j]=v[j]+(matrix[i][j]-'0');
            }
            mx = max(mx,MAH(v));
        }
        return mx;
    }