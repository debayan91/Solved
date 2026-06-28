class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = size(grid);
        int x, y;
        vector<bool> b(n * n, false);
        for(auto a : grid){
            for(int i : a){
                if(b[i - 1]){
                    y = i;
                } else {
                    b[i - 1] = true;
                }
            }
        }
        for(int i = 0; i < size(b); i++) if(!b[i]) x = i + 1;
        return {y, x};
    }
};