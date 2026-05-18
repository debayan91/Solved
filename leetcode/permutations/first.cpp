class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    void backtrack(vector<int>& current, vector<bool>& v, int index){
        if(index == nums.size()){
            res.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!v[i]){
                v[i] = true;
                current[i] = nums[index];
                backtrack(current, v, index + 1);
                v[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        vector<int> current(nums.size());
        vector<bool> v(nums.size());
        backtrack(current, v, 0);
        return res;
    }
};