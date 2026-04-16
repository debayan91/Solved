class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i = 0;i<n;i++){
            s.insert(nums[i]);
        }
        nums.clear();
        for(int x : s) {
            nums.push_back(x);
        }
        return s.size();
    }
};