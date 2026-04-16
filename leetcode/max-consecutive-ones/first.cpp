class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1){
                count = 1;
                i++;
                while(i < nums.size() && nums[i] == 1){
                    count++;
                    i++;
                }
                if(count>max_count) max_count = count;
            }
        }
        return max_count;
    }
};