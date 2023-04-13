/*Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns,
 find the median in the given matrix.*/

/*Step 1: Find the minimum and maximum element in the given array. By just traversing the first column,
we find the minimum element and by just traversing the last column, we find the maximum element.
Step 2: Now find the middle element of the array one by one and check in the matrix how many elements are
present in the matrix.

Three cases can occur:-
If count ==  (r*c+1)/2 , so it may be the answer still we mark max as mid since we are not referring
indices , we are referring the elements and 5 elements can be smaller than 6 also and 7 also ,
so to confirm we mark max as mid.
If count<(r*c+1)/2 , we mark  min as mid+1 since curr element or elements before it cannot be the answer.
If count>(r*c+1)/2 , we mark max as mid , since elements after this can only be the  answer now.*/
#include <bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A)
{
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
int main()
{
  int row = 3, col = 3;
  vector<vector<int>> arr = {{1, 3, 8},
                             {2, 3, 4},
                             {1, 2, 5}};
  cout <<"The median of the row-wise sorted matrix is: "<<findMedian(arr)<<endl;
  return 0;
}

