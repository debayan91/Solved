class Solution {
public:
    int div(int a, int b){
        if(a % b == 0) return a / b;
        return a / b + 1;
    }
    long long result(vector<int>& nums, int di){
        long long sum = 0;
        for(int i : nums) sum += div(i, di);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int res = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(result(nums, mid) <= threshold){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};