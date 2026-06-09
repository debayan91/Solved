class Solution {
public:
    int peak(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(mid + 1 < size(nums) && nums[mid] <= nums[mid + 1]){
                l = mid + 1;
            }else if(mid - 1 > -1 && nums[mid - 1] >= nums[mid]){
                r = mid - 1;
            }else{
                return mid;
            }
        }
        return 0;
    }
    bool ispeak(vector<vector<int>>& grid, int i, int j){
        int a = grid[i][j];
        if(i - 1 > -1 && grid[i - 1][j] >= a) return false;
        if(j - 1 > -1 && grid[i][j - 1] >= a) return false;
        if(i + 1 < size(grid) && grid[i + 1][j] >= a) return false;
        if(j + 1 < size(grid[0]) && grid[i][j + 1] >= a) return false;
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& grid) {
        for(int i = 0; i < size(grid); i++){
            int j = peak(grid[i]);
            if(ispeak(grid, i, j)){
                return {i, j};
            }
        }
        return {};
    }
};