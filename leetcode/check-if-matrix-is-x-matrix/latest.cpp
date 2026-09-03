class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = size(grid);
        int i = 0;
        while(i < n){
            if(grid[i][i] == 0) return 0;
            grid[i][i] = -1;
            i++;
        }
        i = 0;
        int j = n - 1;
        while(i < n){
            if(grid[i][j] == 0) return 0;
            grid[i][j] = -1;
            i++; j--;
        }
        for(auto a : grid){
            for(int b : a){
                if(b == 0 || b == -1){
                    
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
};