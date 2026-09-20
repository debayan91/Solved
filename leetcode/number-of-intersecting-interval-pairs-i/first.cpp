class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<array<int, 2>> e;
        for (auto& i : intervals) {
            e.push_back({i[0], 0}); e.push_back({i[1], 1});
        } sort(begin(e), end(e));
        long long a = 0, count = 0; for(auto& [cc, t] : e){
            if(t == 0){
                count += a++; 
            } else a--;
        }
        return count;
    }
};