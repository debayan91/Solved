class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = size(nums);
        for(int i = 0; i < min(k + 1, n); i++){
            if(st.count(nums[i])) return true;
            st.insert(nums[i]);
        }
        for(int i = k + 1; i < n; i++){
            int index = i - k - 1;
            st.erase(nums[index]);
            if(st.count(nums[i])) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};