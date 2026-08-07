class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = accumulate(nums.begin(), nums.end(), 0, [](int acc, int x) {
            if (!(x % 2)) return acc + x;
            return acc;
        });
        vector<int> res;
        for(auto& a : queries){
            int index = a[1], val = a[0];
            if(nums[index] % 2 == 0) sum -= nums[index];
            nums[index] += val;
            if(!(nums[index] % 2)) sum += nums[index];
            res.push_back(sum);
        }
        return res;
    }
};