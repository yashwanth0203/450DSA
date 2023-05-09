#include <bits/stdc++.h>
using namespace std;

/*In Arithmetic progression Series, we have a formula to find the n'th term which is Tn = a + (n-1)*d, 
where Tn is the n'th term, 'a' is the first term, 'd' is the common difference.
So, for the given question, the above condition can be written as 
b  = a + (n-1)*c ... eq(1)
Now, from eq1, we have two results:-
1). b-a = (n-1)*c 
     which means (b-a)%c==0
2). (b-a)/c = (n-1), now for an AP series, n>=1, right?? But Why?
Now think of it, n is the number of terms in the series, if there is no term in series (n=0), so the 
series doesn't exist. Right.so, for the series to exist, n>=1, so the series may contain 1 number,
2 numbers and so on.*/
int inSequence(int A, int B, int C){
         if(C==0){
            return A==B;
        }
       return (B-A)%C==0 && (B-A)/C>=0;
}

int main(){
    cout<<inSequence(1,3,4);
}