class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int r = accumulate(begin(nums), end(nums), 0); // max sum is if k = 1
        int l = *max_element(begin(nums), end(nums)), res = r; // min sum if k = size(nums)

        auto works = [&](int mx){
            int count = 0, sum = 0;

            for(int a : nums){
                sum += a;
                if(sum > mx){ // found a subarray that sums to max
                    sum = a;
                    count++;
                }
            }

            if(sum <= mx) count++; // element left

            if(count <= k) return 1; // that sum fits all under k -- we can go lower 
            
            return 0;
        };


        while(l <= r){ // possible from max element --> sum of all
            int m = l + (r - l) / 2;
            if(works(m)){
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};