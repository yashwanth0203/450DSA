/*Given three arrays sorted in increasing order. Find the elements that are common in all three
 arrays*/

#include <bits/stdc++.h>
using namespace std;

/*In the first approach we will take three variables i,j,k for each array and when we compare all
three elements if we get the same value all variables are increased but if A<B then it means that 
A element cannot be repeated elsewhere hence we make i++,similarly for j and k.However this approach
prints duplicate elements multiple times*/

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            vector<int>res;
            int i=0,j=0,k=0;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && B[j]==C[k]){
                    res.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j])
                    i++;
                else if(B[j]<C[k])
                    j++;
                else 
                    k++;
            }
            return res;
}

/*To overcome the previous approach problem of avoid duplicates we use variables prev1,prev2,prev3.
In this approach we traverse till we reach the element further which there are no duplicates.Rest step is
same except for updating previous after incrementing the pointers.*/

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            vector<int>res;
            int i=0,j=0,k=0;
            int prev1,prev2,prev3;
            prev1=prev2=prev3=0;
            while(i<n1 && j<n2 && k<n3){
                while(A[i]==prev1 && i<n1)
                    i++;
                while(B[j]==prev2 && j<n2)
                    j++;
                while(C[k]==prev3 && k<n3)
                    k++;
                if (A[i] == B[j] && B[j] == C[k]) {
                    res.push_back(A[i]);
                    prev1 = A[i++];
                    prev2 = B[j++];
                    prev3 = C[k++];
                }
                else if (A[i] < B[j])
                    prev1 = A[i++];
 
                else if (B[j] < C[k])
                    prev2 = B[j++];
                 else
                    prev3 = C[k++];
            }
            return res;
}
