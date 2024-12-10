#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //we can choose at most 2 overlapping events
        //if(we have given vector of vector can we sort it based of the first number of the vector of vector example [[1,3,2],[4,5,2],[1,5,5]])-> should be [[1,3,2],[1,5,5],[4,5,2]]
        sort(events.begin(),events.end(),[](const vector<int>& a,const vector<int>& b){return a[0]<b[0];});
        int maxe=INT_MIN;
        for(int i=0;i<events.size();i++){
            int et=events[i][1];
            int sum=events[i][2];
            for(int j=i+1;j<events.size();j++){
                int st=events[j][0];
                if(et<st){
                    maxe=max(maxe,sum+events[j][2]);
                }
            }
        }
        for(int i=0;i<events.size();i++){
            maxe=max(maxe,events[i][2]);
        }
        return maxe;
    }
    //IT IS SHOWING TLE OF TEST CASE 45/63
    //ITS TIME COMPLEXITY IS 
};