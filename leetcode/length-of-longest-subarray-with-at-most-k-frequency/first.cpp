class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = size(nums); int res = 0, start = 0;
        for(int i = 0; i < n; i++){
            m[nums[i]]++; // add the number
            if(m[nums[i]] > k){
                res = max(res, i - 1 - start + 1);
                for(int j = start; j < i; j++){
                    m[nums[j]]--;
                    if(nums[j] == nums[i]){
                        start = j + 1;
                        break;
                    }
                    //m[nums[i]] = k;
                }
            }
        }
        res = max(res, n - 1 - start + 1);
        return res;
    }
};