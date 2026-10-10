class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int t) {
        int n = size(nums), u = -1, v = -1;
        long long p = LLONG_MIN;
        for(int i= 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && nums[i] + nums[j] == t && nums[i] > nums[j]){
                    long long ww = nums[i] * nums[j]; if(ww > p){
                        p = ww, u = i, v = j;
                    }
                }
            }
        }
        return {u, v};
    }
};

