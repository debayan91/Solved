class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int aa, int bb) {
        int n = size(nums);
        vector<int> e(n + 1, 0),o(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(nums[i] % 2){
                o[i + 1] = o[i] + 1;
                e[i + 1] = e[i];
            } else {
                e[i + 1] = e[i] + 1;
                o[i + 1] = o[i];
            }
        }
        long long res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j< n; j++){
                int x = e[j + 1] - e[i];
                int y = o[j + 1] - o[i];
                if(y != 0){
                    if(1LL * bb * x <= 1LL * aa * y) res++;
                }
            }
        }
        return res;
    }
};