/*Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on.
 You are given a number N, you have to output the number of integers less than N in the sample space S.*/

#include <bits/stdc++.h>
using namespace std;

int countSquares(int N) {
        int i=1;
        int count=0;
        while(i<N){
            if(i*i<N)
                count++;
            else
                break;
            i++;
        }
        return count;
    }

int main(){
    cout<<countSquares(9);
}