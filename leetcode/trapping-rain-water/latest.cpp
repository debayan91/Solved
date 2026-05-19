class Solution {
public:
    int trap(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int n = nums.size();
        while (nums[i] == 0 && i < n - 1)
            i++;
        while (nums[j] == 0 && j > 0)
            j--;

        int max = max_element(nums.begin(), nums.end()) - nums.begin();
        
        int first = -1;
        int last = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[max]){
                if(first == -1) first = last = i;
                else last = i;
            }
        }

        int water = 0;

        // increasing to first max
        while (i < max) {
            int current = nums[i++];
            while (nums[i] <= current && i <= max) {
                water += (current - nums[i]);
                i++;
            }
        }

        // between maxes

        for(int i = first; i < last; i++){
            water += nums[max] - nums[i];
        }

        // decreasing from last max
        i = j;

        while (nums[i] < nums[max]) {
            int current = nums[i--];
            while (nums[i] <= current && nums[i] <= nums[max]) {
                water += (current - nums[i]);
                i--;
            }
        }

        return water;
    }
};