class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        for(int i = 1; i > 0; i *= 2){
            if(!st.count(i)) return i;
        }
        return 0;
    }
};