class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& ints, int a, int b) {
        sort(begin(ints), end(ints), [](auto& a, auto& b){
           return a[0] < b[0]; 
        });
        vector<vector<int>> merged;
        for(auto& i : ints){
            if(size(merged) == 0 || i[0] > merged.back()[1] + 1){
                merged.push_back(i);
            } else {
                merged.back()[1] = max(merged.back()[1], i[1]);
            }
        }
        vector<vector<int>> res;
        for(auto& i : merged){
            int l = i[0];
            int r = i[1];

            if(r < a || l > b){
                res.push_back({l, r});
            }
            // else if(l >= a && r <=  b){
            //     continue;
            // }
            // else if(l < a || r > b){
            //     res.push_back({l, a - 1});
            //     res.push_back({b + 1, r});
            // }
            // else if(l < a){
            //     res.push_back({l, a - 1});
            // }
            else {
                // res.push_back({l, a - 1});
                if(l < a){
                    res.push_back({l, a - 1});
                }
                if(r > b){
                    res.push_back({b + 1, r});
                }
            }
        }
        return res;
    }
};