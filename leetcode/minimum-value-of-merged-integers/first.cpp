class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mn = INT_MAX;
        for(int i = 0; i < size(nums) - 1; i += 2){
            string s = to_string(nums[i]) + to_string(nums[i + 1]);
            mn = min(mn, stoi(s));
        }
        return mn;
    }
};