/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.
*/

/*The brute force approach would be to take two loops and take count of each element.The better approach 
would be to take a hashmap and store the frequencies.The better approach must be solved without using
space.*/

/*The approach is simple.There could be only one majority element in an array and mo matter the size
its count will be atleast 1 even when we subtract it while encountering other elements.Lets consider
this as life.Initially candidate would be first element and life=1 now whenever we encounter the same
element as candidate we increase the life if not we decrease the life but when the life is 0 it means
that the life would have not been 0 if its majority element till then so we replace the majority
element candidate by that element and make life to 1. At last the element which is candidate is the majority
element.For detailed explanation look at code with Alisha channel she explained excellently.*/
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int life=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==candidate)
                life++;
            else if(life==0){
                candidate=nums[i];
                life=1;
            }
            else life--;
        }
        return candidate;
    }

int main(){
    vector<int>arr={2,2,1,1,1,2,2};
    cout<<majorityElement(arr);
}