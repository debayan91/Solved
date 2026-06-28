class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(begin(nums), end(nums), greater<int>());
        unsigned long long sum = 0;
        for(int j = 0; j < k; j++){
            unsigned long long i = nums[j];
            if(mul > 1){
                unsigned long long k = i * mul;
                sum += k;
            }else{
                sum += i;
            }
            mul--;
        }
        return sum;
    }
};