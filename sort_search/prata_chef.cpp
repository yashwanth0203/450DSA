/*
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The 
subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function.
The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata
in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can 
only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes 
one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he 
cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th 
prata). The webmaster wants to know the minimum time to get the order done. Please write a program to 
help him out.*/


/*The appraoch is simple check for each certain time where parathas can be made using binary search.
If its possible try to minimise time and check if further possible else return minimum time.The similar
problems are shipping capacity,flower bouqets,minimum allocation,painter partition,EKOSPOJ in gfg,spoj
and leetcode*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int arr[], int pratas, int mid) {
    int time = 0;
    int prata = 0;
    for(int i = 0; i < n; i++) {
        time=arr[i];
        int j=2;
        while(time <=mid) {
            prata++;
            time+=arr[i]*j;
            j++;
        }
    }
    if( prata>=pratas)
        return true;
    else
        return false;
}

int findPrata(int A[], int N, int pratas) {
    int low = 0;
    int high = 1e8;
    int res = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isValid(N, A, pratas, mid) == true) {
            high = mid - 1;
            res = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    int arr[]={4,1,2,3,4};
    cout<<findPrata(arr,5,10);
}