class Solution {
public:
    vector<int> overlap(vector<int>& a, vector<int>& b){
        int x, y;
        if(a[1] >= b[0] && a[0] <= b[1]){
            x = max(a[0], b[0]);
            y = min(a[1], b[1]);
            return {x, y};
        }
        return {-1, -1};
    }
    int findMinArrowShots(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 1;

        int count = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> ov = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            vector<int> current = overlap(intervals[i], ov);
            if(current[0] == -1){ // there is no overlap
                count++;
                ov = intervals[i];
            }else{
                ov = current;
            }
        }
        count++;

        return count;
    }
};