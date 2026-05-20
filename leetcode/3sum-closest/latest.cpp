class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int minsum = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int c = nums[i];
            // 2 pointers
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int total = c + nums[l] + nums[r];
                int d = target - total;
                d = d < 0 ? d * -1 : d;
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