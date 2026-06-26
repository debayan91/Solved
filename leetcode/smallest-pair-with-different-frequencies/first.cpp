class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> u;
        for(int i : nums) u[i]++;
        sort(begin(nums), end(nums));
        for(int i = 0; i < size(nums) - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] < nums[j] && u[nums[i]] != u[nums[j]]){
                    res = {nums[i], nums[j]};
                    return res;
                }
            }
        }
        return {-1, -1};
    }
};