class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(int n : nums){
                if(n & (1 << i)) count++;
            }
            if(count % 3) res = res | (1 << i);
        }
        return res;
    }
};