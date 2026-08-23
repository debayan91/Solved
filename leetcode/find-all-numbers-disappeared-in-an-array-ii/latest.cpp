class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int l, int h) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        int i = 0, n = size(nums);
        while(i < n && nums[i] < l) i++;
        if(i == n || nums[i] > h){
            return {{l, h}};
        } 
        if(nums[i] > l) res.push_back({l, nums[i] - 1});;
        while(i + 1 < n){
            if(nums[i + 1] > h) break;
            if(nums[i + 1] > nums[i] + 1) res.push_back({nums[i] + 1, nums[i + 1] - 1});
            i++;
        }
        if(nums[i] < h) res.push_back({nums[i] + 1, h});;
        return res;
    }
};