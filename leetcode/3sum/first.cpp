class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> st;
    vector<int> nums;

    void two(int element, int l, int r){
        int target = 0 - element;
        while(l < r){
            if(nums[l] + nums[r] == target){
                st.insert({element, nums[l], nums[r]});
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < target){
                l++;
            }else r--;
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        for(int i = 0; i < nums.size(); i++){
            two(nums[i], i + 1, nums.size() - 1);
        }
        for(auto i : st) res.push_back(i);
        return res;
    }
};