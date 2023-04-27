/*Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird
person and follows a certain rule when looting the houses. According to the rule, he will never loot
two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows
which house has what amount of money but is unable to come up with an optimal looting strategy. He asks
for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]
amount of money present in it.*/

/*The appraoch is same as house robber leetcode refer my notes for explanation.*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static int FindMaxSum(int arr[], int n){
        vector<int> memo(n + 1, -1);
        return houseRob(arr, 0, n, memo);
    }

    static int houseRob(int arr[], int n, int size, vector<int> &memo){
        if(n<0 || n>=size)
            return 0;
        if(memo[n]!=-1) return memo[n];

        int ans=max(houseRob(arr,n+2,size,memo)+arr[n],houseRob(arr,n+1,size,memo));
        return memo[n]=ans;
    }
};

int main(){
    int arr[]={5,5,10,100,10,5};
    Solution sol;
    cout<<sol.FindMaxSum(arr,6);
}
