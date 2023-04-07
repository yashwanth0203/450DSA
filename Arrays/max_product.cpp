/*Given an array Arr[] that contains N integers (may be positive, negative or zero).
 Find the product of the maximum product subarray.
The approach would be maximum product will be product of all array elements.This would be possible
if all the elements are either non zero and there would be even number of elements or all positive elements
But if all the elements are negative and number is odd then we have to leave either first or last
element looking at the maximum product*/

 int maxProduct(vector<int>& arr) {
        int ans=INT_MIN;
        int product=1;
        int n=arr.size();
   for(int i=0;i<n;i++){
       product*=arr[i];
       ans=max(ans,product);
       if(arr[i]==0){product=1;}
   }
    
   product=1;
    
   for(int i=n-1;i>=0;i--){
       product*=arr[i];
       ans=max(ans,product);
       if(arr[i]==0){product=1;}
   }
   return ans;
    }