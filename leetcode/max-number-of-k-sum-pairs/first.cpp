class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int h = nums.size() - 1;
        int count = 0;
        while(l < h){
            if(nums[l] + nums[h] == k){
                count++;
                nums[l] = 0;
                nums[h] = 0;
                l++;
                h--;
            }else if(nums[l] + nums[h] > k){
                h--;
            }else{
                l++;
            }
        }
        return count;
    }
};