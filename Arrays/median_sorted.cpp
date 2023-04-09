/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two 
sorted arrays.
The overall run time complexity should be O(log (m+n)).*/

/*       Find approximate positions where the two lists are grouped into left and right
        such that max(left)<=min(right).
        This convergence is accompanied by binary searching to ignore processed every half range.
        ex: if left group was split, then it means right group is already good for this list
            and vice versa
            so we ignore right group and limit upper bound to left group only and try for convergence
    partitioning:
        1. divide both arrays into equal halves such that count(left_halves) = count(right_halves) 
            NOTE: count(left_group) == count(right_group) (left group may have +1 if odd total size)
        2. l1, l2 are max in left groups
            r1, r2 are min in right groups
        3. we already know that l1<=r1; l2<=r2 (since both input arrays are already sorted)
            so the partition point must be such that l1<=r2 and l2<=r1 
            such that max(left_group) <= min(right_group); 
            This is the median point (NOTE: we still have left_group_count(+1) == right_group_count)
        if we didn't satisfy above condition it must be either from these 2 cases:
            a. l1 > r2 (right_group contains some elements that were intended for left_group)
            b. l2 > r1 (left_group contains some elements that were intended for right_group)
            which are the cases that are required for valid paritioning
            if l1 > r2:
                move l1 from left to right group and move r2 from right to left group 
                by limiting left group of list 1 to (0, m1/2)
                Since list-2's mid m2 is directly dependant on m1, 
                its right range shrinks to (m2+(m2/2), n2) which compensates the shrink in list1
                accomplished by:
                    hi1 = m1-1 
            similarly
            if l2 > r1:
                move l2 from left to right group and move r1 from right to left group 
                by increasing left group of list 1 to (m1/2, n1)
                Since list-2's mid m2 is directly dependant on m1, 
                its left range shrinks by half to (0, m2/2) which compensates the increase in list1
                accomplished by:
                    hi1 = m1-1 
        4. m1 = (lo1+hi1) which either shifts to left or right by half (when partitioning is still required)
        5. m2 which is dependant on m1 so that it compensates for shifts caused by m1
           merged_mid = (n1+n2)/2
           m2 = merged_mid-m1 
           or 
           m1 + m2 + (-1) => merged_mid
           m1 + m2 = ((n1+n2)+1)//2  (offset of +1 to have more items on left group if n1+n2 is odd)*/
//For brief explanation watch Keerti Purswani youtube video
#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2) {
        swap(nums1, nums2);
        swap(n1, n2);
    }

    int total = n1 + n2;
    int half = (total) / 2;

    int left = 0;
    int right = n1;

    while (left <= right) {
        int cut1 = (left + right) / 2;
        int cut2 = half - cut1;

        int l1=cut1==0?INT_MIN:nums1[cut1-1];
        int l2=cut2==0?INT_MIN:nums2[cut2-1];
        int r1=cut1==n1?INT_MAX:nums1[cut1];
        int r2=cut2==n2?INT_MAX:nums2[cut2];

        if(l1>r2)
            right=cut1-1;
        else if(l2>r1)
            left=cut1+1;
        else 
            return (n1+n2)%2==0?(max(l1,l2)+min(r1,r2))/2.0:min(r1,r2);
    }

    return 0.0;  // To avoid compiler warnings
}

int main(){
    vector<int>nums1 = {1,2};
    vector<int>nums2 = {3,4};
    cout<<findMedianSortedArrays(nums1,nums2);
}