class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        // maximize h = nums[i] >= n - i ? n - i : 0; 
        int l = 0;
        int r = n - 1;

        int max = 0;

        while(l <= r){
            int mid = (l + r) / 2;

            int h = nums[mid] >= n - mid ? n - mid : 0;
            max = h > max ? h : max;

            if(mid - 1 >= 0 && nums[mid - 1] >= n - mid + 1){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return max;
    }
};