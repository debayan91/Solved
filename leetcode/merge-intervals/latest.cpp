class Solution {
public:
    vector<int> overlap(vector<int>& a, vector<int>& b){
        int x, y;
        if(a[1] >= b[0] && a[0] <= b[1]){
            x = min(a[0], b[0]);
            y = max(a[1], b[1]);
            return {x, y};
        }
        return {-1, -1};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> ov = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            vector<int> current = overlap(intervals[i], ov);
            if(current[0] == -1){ // there is no overlap
                res.push_back(ov);
                ov = intervals[i];
            }else{
                ov = current;
            }
        }
        res.push_back(ov);
        return res;
    }
};