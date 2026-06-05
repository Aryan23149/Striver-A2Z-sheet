//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<vector<int>> data_structure(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            int start_time=start[i];
            int end_time=end[i];
            //int order=i+1;
            data_structure[i]={start_time,end_time};
        }
        sort(data_structure.begin(), data_structure.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];  // Sort in increasing order of the 2nd element
            });
        int start_time=0;
        int end_time=0;
        int traversed=0;
        int meetings=0;
        for(int i=0;i<n;i++){
            start_time=data_structure[i][0];
            end_time=data_structure[i][1];
            if(start_time>traversed){
                meetings++;
                traversed=end_time;
            }
        }
        return meetings;
        // int n = start.size();
        // vector<vector<int>> meetings(n, vector<int>(2));

        // for(int i = 0; i < n; i++) {
        //     meetings[i] = {end[i], start[i]}; // sort by end time
        // }

        // sort(meetings.begin(), meetings.end()); // sorts by end time, then by start time

        // int count = 0;
        // int last_end = -1;

        // for(int i = 0; i < n; i++) {
        //     if(meetings[i][1] > last_end) {
        //         count++;
        //         last_end = meetings[i][0];
        //     }
        // }

        // return count;
    }
};