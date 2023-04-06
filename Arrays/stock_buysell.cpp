/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day
in the future to sell that stock.Return the maximum profit you can achieve from this transaction. If you
 cannot achieve any profit, return 0.*/


/*Logic is simple just maintain a minimum element till cuurent iteration and subtract it from current
and look at max difference.*/
 #include <bits/stdc++.h>
 using namespace std;

 int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;

        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
}

int main(){
    vector<int>arr={7,1,5,3,6,4};
    cout<<maxProfit(arr);
}