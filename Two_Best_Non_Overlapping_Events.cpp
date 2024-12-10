#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //we can choose at most 2 overlapping events
        //if(we have given vector of vector can we sort it based of the first number of the vector of vector example [[1,3,2],[4,5,2],[1,5,5]])-> should be [[1,3,2],[1,5,5],[4,5,2]]
        //we have sorted the events based on the start time
        sort(events.begin(),events.end(),[](const vector<int>& a,const vector<int>& b){return a[0]<b[0];});
        //we have to create a suffix array
        int n=events.size();
        vector<int> suffix(n);
        suffix[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],events[i][2]);
        }
        int maxe=INT_MIN;
        //we are going to use binary search to find the best non overlapping events
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            int next_event_index=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(events[mid][0]>events[i][1]){
                    next_event_index=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(next_event_index!=-1){
                maxe=max(maxe,events[i][2]+suffix[next_event_index]);
            }
            maxe=max(maxe,events[i][2]);
        }
        return maxe;
        // for(int i=0;i<n;i++){
        //     int et=events[i][1];
        //     int sum=events[i][2];
        //     for(int j=i+1;j<n;j++){
        //         int st=events[j][0];
        //         if(et<st){
        //             maxe=max(maxe,sum+events[j][2]);
        //         }
        //     }
        // }
        // for(int i=0;i<events.size();i++){
        //     maxe=max(maxe,events[i][2]);
        // }
        // return maxe;
    }
    //IT IS SHOWING TLE OF TEST CASE 45/63
    //ITS TIME COMPLEXITY IS O(N^2)
    //Constraints:
    //2 <= events.length <= 10^5
    //events[i].length == 3
    //1 <= startTimei <= endTimei <= 10^9
    //1 <= valuei <= 10^6
    //why this is not working because we are checking for all the events for each event which is not optimal 
    //As events.length is 10^5 and its time complexity is O(N^2) 10^5*10^5=10^10 which is not optimal and it will not run in 1 sec because we know in 1 sec 10^8 operations can be done
    //So we need to optimize it.


};