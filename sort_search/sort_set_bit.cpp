/**/
#include <bits/stdc++.h>
using namespace std;

// Brian Kernighan’s Algorithm

int countBits(int N)
{ 
  int Count = 0;
  while(N)
  {
    N = N & (N-1);
    Count+=1;
  }
  return Count;
}
 
// custom comparator of std::sort

int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
    return (count1 > count2);
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

unsigned int countSetBits2(unsigned int n)
   {
      unsigned int count = 0;
       while (n) {
        count += n & 1;
        n >>= 1;
       }
      return count;
    }
    void sortBySetBitCount2(int arr[], int n)
    {
        // Your code goes here
        multimap<int,int,greater<int>>mp;
        for(int i = 0;i < n;i++){
            unsigned int count = countSetBits2(arr[i]);
            mp.insert({count,arr[i]});
        }
        int i = 0;
        for(auto it : mp){
            arr[i] = it.second;i++;
        }
    }
int main()
{
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    stable_sort(arr, arr + n, cmp);
    printArr(arr, n);
    return 0;
}