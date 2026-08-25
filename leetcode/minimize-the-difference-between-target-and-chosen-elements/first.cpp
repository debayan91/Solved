class Solution {
public:
    int mn = INT_MAX;
    void back(vector<vector<int>>& mat, int target, vector<vector<bool>>& possible, int i, int j, int sum){
        int m = size(mat), n = size(mat[0]);
        if(i == m){
            mn = min(mn, abs(sum - target));
            return;
        }
        sum += mat[i][j];
        if(!possible[i][sum]) possible[i][sum] = 1; else return;
        for(int k = 0; k < n; k++){
            back(mat, target, possible, i + 1, k, sum);
        }
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = size(mat), n = size(mat[0]);
        vector<vector<bool>> possible(m + 1, vector<bool>(5000));
        for(int i = 0; i < n; i++) back(mat, target, possible, 0, i, 0);
        return mn;
    }
};