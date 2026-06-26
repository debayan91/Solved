class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int m = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
               if(i != j && abs(i - j) < m && 
                      (
                          (nums[i] == 1 && nums[j] == 2) || (nums[i] == 2 && nums[j] == 1)
                      )
                 ) {
                   m = abs(i - j);
                 }
            }
        }
        return m == INT_MAX ? -1 : m;
    }
};