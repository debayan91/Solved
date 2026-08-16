class Solution {
public:
    int nearestDrone(vector<vector<int>>& d, vector<int>& t) {
        int mn = INT_MAX;
        int res = -1;
        for(int i = 0; i < size(d); i++){
            int m = abs(d[i][0] - t[0]) +  abs(d[i][1] - t[1]);
            if(m > d[i][2]) continue;
            if(m < mn){
                mn = m;
                res = i;
            }
        }
        return res;
    }
};