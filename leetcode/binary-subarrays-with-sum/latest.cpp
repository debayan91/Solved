class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = size(nums), current = 0, res = 0;
        if(goal == 0){
            while(r < n){
                if(nums[r] == 1) {r++; continue;}
                int count = 0;
                while(r < n && nums[r] == 0){
                    count++;
                    r++;
                }
                res += count * (count + 1) / 2;
            }
            return res;
        }
        while(r < n){
            if(nums[r] == 1){
                current++;
            }
            if(current == goal){
                int a = 0, b = 0;
                while(r + 1 < n && nums[r + 1] == 0){ // extend to the right
                    r++;
                    a++;
                }
                while(l < r && nums[l] == 0){ // extend to the left;
                    l++;
                    b++;
                }
                res += (a + 1) * (b + 1);
                l++; // push out a 1
                current--;
            }
            r++;
        }
        return res;
    }
};