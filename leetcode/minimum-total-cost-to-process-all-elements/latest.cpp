class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int mod = 1e9 + 7;
        __int128 avl = k;
        __int128 cost = 1;
        long long csum = 0;
        for (int i = 0; i < size(nums); i++) {
            if(avl < nums[i]){
                __int128 need = ((__int128)nums[i] - avl + k - 1) / k;
                avl += (need * (__int128)k);

                __int128 add = need * ((__int128)2 * cost + need - 1);
                add /= 2;
                
                csum = (csum + (long long)(add % mod)) % mod;
                cost += need;
            }
            avl -= nums[i];
        }
        return csum;
    }
};