#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    static bool compare(std::vector<int>&a,std::vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(),compare);
        int prevend=intervals[0][1];
        int currentstart;
        int intercount=0;
        for(int i=1;i<intervals.size();i++)
        {
            currentstart=intervals[i][0];
            if(prevend>currentstart)
            {
                intercount++;
            }
            else
                prevend=intervals[i][1];
        }
        return intercount;
    }
};