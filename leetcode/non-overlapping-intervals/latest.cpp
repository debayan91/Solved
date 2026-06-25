class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int count = 0;
        int prev_end = nums[0][1];
        for(int i = 1; i < size(nums); i++){
            int a = prev_end;
            int b = nums[i][0];
            if(a > b){
                count++;
            }
            else prev_end = nums[i][1];
        }
        return count;
    }
};