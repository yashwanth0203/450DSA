/*Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to 
find the element that would be at the kth position of the final sorted array.*/

/*The naive approach is to use two pointers one for each array and comapring and increasing the count
when we reach k return min of both pointers.*/

/*The approach we use is the binary search without using extra space.This approach is same as median
of two sorted arrays discussed previously in arrays part.The approach is simple perform the binary search
on the array with least number of elements.Take low to be 0 and high to be k.Now take cut1 ar mid the
rest elements can be taken from second array now it would technically result in four parts l1 and l2
and r1 and r2.Though we made the cut we are not sure whether they are sorted as whole though they are
cutted sortedly for individual array.To do this we need to check if l1<=r2 and l2<=r1 if thats the case
it means the array is sorted.If l1>r2 that means we need to shift left so we make high=end-1 else if
l2>r1 it means we have to shift r2 to right so low=mid+1 and this process is continued.When we meet
the desired condition there will be k elements on each side but we dont know which is kth element
since we do not arrange both the arrays in sorted array so we take max of l1 and l2 since technically
it would be the largest in that half which is the kth element and that can be returned.Now there could
be some cases where the k is greater than size of both the individual arrays.In that case we cant keep
low as 0 since the left half must accomodate some from first array hence we use condition of low=
max(0,k-m)where m is size of larger array.Similarly this done for larger array.Here n = 4 and m=6 and k=7.
Since k>m , so we can't take 0 elements as the lowest no. of elements picked from array1 . It should be
(k-m) i.e. 7-6=1 and the high is obvious min(k,n) i.e min(7,4) i.e 4 (4 elements can be taken at max
 from array 1) */
#include <bits/stdc++.h>
using namespace std;

int median(vector<int>& nums1, vector<int>& nums2,int k){
        int n=nums1.size(),m=nums2.size(),x=k,sum=0;

        
        int l = max(0,k-m) ,r = min(k,n) ,l2,r2,l1,r1;
        int cut1 = (l+r)/2,cut2 = x-cut1;
        
        while(l<=r){
            cut1 = (l+r)/2;
            cut2 = x-cut1;
            l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
            l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
            r1 = (cut1 == n)? INT_MAX:nums1[cut1];
            r2 = (cut2 == m)? INT_MAX:nums2[cut2];
            if(l1>r2){
                r = cut1-1;
            }
            else if(l2>r1){
                l = cut1+1;
            }
            else{
                
                return max(l1,l2);
            }   
        } 
        return 0;
}

int main(){
    vector<int>v1={2, 3, 6, 7, 9};
    vector<int>v2={1, 4, 8, 10};
    cout<<median(v1,v2,5);
}