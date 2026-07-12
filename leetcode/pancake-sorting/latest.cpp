class Solution {
public:
    vector<int> pancakeSort(vector<int>& nums) {
        vector<int> res;
        int n = size(nums);
        int r = n - 1;
        while(r >= 0){
            int index = max_element(begin(nums), begin(nums) + r + 1) - begin(nums);
            if(index == r) r--;
            else if(index > 0){
                reverse(begin(nums), begin(nums) + index + 1);
                reverse(begin(nums), begin(nums) + r + 1);
                res.push_back(index + 1);
                res.push_back(r + 1);
                r--;
            } else {
                reverse(begin(nums), begin(nums) + r + 1);
                res.push_back(r + 1);
                r--;
            }
        }
        return res;
    }
};