class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = size(nums);
        vector<int> res;
        for(int i = 0; i < n; i++){
            for(int j = i - k; j <= i + k; j++){
                if(j >= 0 && j < n && nums[j] == key){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};