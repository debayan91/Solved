class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long start = 0;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == 0){
                start = i;
                while(i < size(nums) && nums[i] == 0){
                    i++;
                }
                long long end = i; 
                long long n = (end - start);
                count += (n * (n + 1)) / 2;
            }else{
                i++;
            }
        }
        return count;
    }
};