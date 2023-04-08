/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you
 buy again).*/

/*We have to make sure that the two transactions must follow the order buy-sell-buy-sell.If we use the 
method of stock buy and sell where we update min and find max by subtracting max from current element
thats not gonna work the reason being we need to know from which the buy has been started or you may say
the index at which the share bought gave maximum profit so that we can buy and sell before that.In the
previous approach it would give the index at which maximum profit sold which is not required.So we traverse
from backwards for first max transaction by updating max everytime and subtracting from current element
to obtain max profit.We need to note that the value at a current index denotes the maximum profit from
that index after first transaction.We can note that during first transaction we keep buying pointer and
during second transaction we keep track of selling pointer.FOr detailed explanation visit Ayushi Sharma
Channel*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int *profit=new int[n];
        for(int i=0;i<n;i++)
            profit[i]=0;
        int max_price=prices[n-1];
        for(int i=n-2;i>=0;i--){
            max_price=max(max_price,prices[i]);
            profit[i]=max(profit[i+1],max_price-prices[i]);
        }
        int min_price=prices[0];
        for(int i=1;i<n;i++){
            min_price=min(min_price,prices[i]);
            profit[i]=max(profit[i-1],profit[i]+prices[i]-min_price);
        }
        return profit[n-1];
}

int main(){
    vector<int>arr={3,3,5,0,0,3,1,4};
    cout<<maxProfit(arr);
}