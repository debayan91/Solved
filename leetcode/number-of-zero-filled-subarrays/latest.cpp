class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        long long count = 0;
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] == 0){
                count++;
                res += count;
            }else{
                count = 0;
            }
            i++;
        }
        return res;
    }
};