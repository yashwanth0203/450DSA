/*Given an array of positive integers. Find the length of the longest sub-sequence such that elements
 in the subsequence are consecutive integers, the consecutive numbers can be in any order.*/

 /*Our approach is we take a ordered map so that all the keys are sorted.We insert all the values
 in ordered map.Since we dont know at what value the map starts,to check the consecutivity we can 
 check with previous element and increase the count and when it didnt we can make count=1 which means
 we have to start checking for new sequence from that elements next*/

int findLongestConseqSubseq(int arr[], int N)
{
  map<int,int>mp;
  for(int i=0;i<N;i++)
    mp[arr[i]]++;

  int maxi=1;
  int count=1;
  int prev=mp.begin()->first;
  for(auto it:mp){
      if(prev==(it.first-1)){
          count++;
          maxi=max(maxi,count);
      }
      else
          count=1;
      prev=it.first;
  }
  return maxi;
}