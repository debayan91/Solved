class Solution {
public:
    bool isBalanced(string nums) {
        int sum = 0;
        for(int i = 0; i <size(nums); i++){
            if(i%2 == 0) sum += nums[i] - '0';
            else sum -= nums[i] - '0';
        }
        return sum == 0;
    }
};