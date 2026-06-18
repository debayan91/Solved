class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;
        sort(begin(nums), end(nums));
        for (int i = 0; i < size(nums); i++) {
            if(m.count(nums[i]) && m[nums[i]] > 0){
                int count = 0;
                int number = nums[i];
                while(count < k && m.count(number) && m[number] > 0){
                    m[number]--;
                    number++;
                    count++;
                }
                if(count != k){
                    return false;
                }
            }
        }
        return true;
    }
};