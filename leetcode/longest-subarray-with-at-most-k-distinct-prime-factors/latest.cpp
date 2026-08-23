class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = size(nums);
        vector<vector<int>> f;
        for(int i = 0; i < n; i++){
            vector<int> pf;
            int kk = nums[i];
            for(int j = 2; j * j <= kk; j++){
                if(kk % j == 0){
                    pf.push_back(j);
                    while(kk % j == 0) kk /= j;
                }
            }
            if(kk > 1) pf.push_back(kk);
            f.push_back(pf);
        }
        unordered_map<int, int> m; int l = 0, res = 0;
        for(int i = 0; i < n; i++){
            for(int p : f[i]) m[p]++;
            while(size(m) > k){
                for(int p : f[l]){
                    m[p]--;
                    if(!m[p]) m.erase(p);
                }
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};