class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sz = nums.size();
        int avg = accumulate(nums.begin(), nums.end(), 0)/sz;
        sort(nums.begin(), nums.end());
        if(avg < 0)
            avg = 1;
        else
            avg += 1;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] < avg)
                ++i;
            else if(nums[i] == avg)
                ++avg;
            else if(nums[i] > avg)
                return avg;
        }
        return avg;
    }
};