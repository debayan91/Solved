class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int minsum = -1;
        for(int i = 0; i < nums.size(); i++){
            int c = nums[i];
            // 2 pointers
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int total = c + nums[l] + nums[r];
                int d = abs(target - total);
                if(d < diff){
                    diff = d;
                    minsum = total;
                }

                if(target == total) return target;

                if(target < total){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return minsum;
    }
};