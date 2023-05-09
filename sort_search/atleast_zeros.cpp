
/*Approach: number of 2 and 5 in an factorial array decides number of trailing 0. also, we can observe in
prime factor of any number's factorial that 2's are more than 5's so we need to find minimum count of 
(5 and 2) in an factorial. we need not find count of 2 because until we have matching 5, it wont create 
trailing 0.so, problem reduces to finding number of 5 factors.how to find number of 5 factor :
countOf5 = n/5 + n/5*5 + n/(5*5*5)  ..... so on. for given value of n.
example: n=20 there will be 5 factors -> 5, 10(5*2), 15(5*3), 20(5*4).
n=25 there will be 6 factors because 25 = 5*5 it gives one extra 5 to be multiplied with available 2 (which comes from number ending with 2, 4, 6, 8). 
n=30 there will be 7 factors because upto 25 -> its 6 then 30(6*5) . so other way to find
30.   30
-  +  --   = 7
5.    25  
N      N         N                N
general equation to count of digit(d) in a series is  -- +   --   +   ---  .........    ---     until
d*d*d*.. becomes greater than N.
d.    d*d.    d*d*d          d*d*d...
why Binary search                                                                   
Since we know that our answer lies between 0 to n*5 depending on cout digits in series, we can apply 
binary search between 0 to n*5*/

#include<bits/stdc++.h>
using namespace std;
int solve(int n)
        {
            int ans=0;
            while(n>0){
                ans+=n/5;
                n/=5;
            }
            return ans;
        }
        int findNum(int n){
            int lo=1;
            int hi=n*5;
            int ans;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(solve(mid)>=n){
                    hi=mid-1;
                    ans=mid;
                }
                else lo=mid+1;
            }
            return ans;
        }

int main(){
    cout<<findNum(5);
}