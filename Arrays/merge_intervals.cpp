/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 and return an array of the non-overlapping intervals that cover all the intervals in the input.*/

/*We need to observe that when the first element of curInterval is less than second element of prevInterval
we need to merge since they are overlapping  and the end index would be max end of both intervals
Here though we make auto it its starting from 1st index instead of 0 reason being intervals[0] is already
being assigned so iteration starts from 1st index.*/
 #include <bits/stdc++.h>
 using namespace std;

 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int>prevInterval=intervals[0];
        for(auto curInterval:intervals){
            if(prevInterval[1]>=curInterval[0])
                prevInterval[1]=max(curInterval[1],prevInterval[1]);
            else{
                mergedIntervals.push_back(prevInterval);
                prevInterval=curInterval;
            }
        }
        mergedIntervals.push_back(prevInterval);
        return mergedIntervals;
}

int main(){
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    merge(arr);
}