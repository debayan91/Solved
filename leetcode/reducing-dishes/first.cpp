class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                int mul = 1;
                int sum = 0;
                for(int j = i; j < nums.size(); j++){
                    sum += nums[j] * mul++;
                }
                if(sum > res) res = sum;
            }else{
                int mul = 1;
                int sum = 0;
                for(int j = i; j < nums.size(); j++){
                    sum += nums[j] * mul++;
                }
                if(sum > res) res = sum;
                break;
            }
        }
        return res;
    }
};