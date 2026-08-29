class Solution {
public:
    int maxValidSplit(vector<int>& nums) {
        int n = size(nums);
        int gc = 1; vector<int> pr(n), sf(n); pr[0] = nums[0]; sf[n - 1] = nums.back();
        for(int i = 1; i < n; i++){
            pr[i] = gcd(pr[i - 1], nums[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            sf[i] = gcd(nums[i], sf[i + 1]);
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++){
            if(pr[i] == sf[i + 1]) res++;
        }
        // for(int i = 0; i < n - 2; i++){
        //     if(pr[i] == sf[i + 2]) res++;
        // }
        return res;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = size(nums);
        if(n < 2) return 0;
        int res = maxValidSplit(nums);
        for(int i = 0; i < n; i++){
            int val = nums[i]; nums.erase(begin(nums) + i); res = max(res, maxValidSplit(nums));
            nums.insert(begin(nums) + i, val);
        }
        return res;
    }
};