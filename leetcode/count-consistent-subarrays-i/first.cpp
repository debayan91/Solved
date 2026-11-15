class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = size(nums), count = 0;
        for(int i = 0; i < n; i++){
            int a = nums[i];
            int mn = a;
            for(int j = i; j < n; j++){
                a &= nums[j], mn = min(mn, nums[j]); if(a == mn) count++;
            }
            
        }
        return count;
    }
};