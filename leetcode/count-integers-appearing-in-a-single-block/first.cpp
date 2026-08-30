class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> st, str;
        int n = size(nums), i = 0;
        while(i < n){
            int val = nums[i];
            while(i < n && nums[i] == val) i++;
            if(st.count(val)) str.insert(val);
            else st.insert(val);
        }
        return max(0, (int)(size(st) - size(str)));
    }
};