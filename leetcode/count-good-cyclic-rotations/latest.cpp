class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = size(nums);
        long long s1 = 0, s2 = 0;
        for(long long i = 0; i < n; i++){
            if(i < n / 2) s1 += nums[i];
            else s2 += nums[i];
        }
        long long i = 0;
        long long j = n / 2;
        long long count = n - 1, res = 0;
        if(s1 > s2) res++;
        while(count--){
            s1 -= nums[i];
            s1 += nums[j];

            s2 -= nums[j];
            s2 += nums[i];

            i = (i + 1) % n;
            j = (j + 1) % n;
            
            if(s1 > s2) res++;
        }
        return res;
    }
};