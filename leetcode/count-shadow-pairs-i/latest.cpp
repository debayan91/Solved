class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long res = 0;
        vector<array<int, 2>> st; int count = 0;
        for(int i : nums){
            while(!st.empty() && st.back()[0] > i){
                count -= st.back()[1]; st.pop_back();
            }
            int eq = (!st.empty() && st.back()[0] == i) ? st.back()[1] : 0;
            res += count - eq;
            if(!st.empty() && st.back()[0] == i) st.back()[1]++;
            else st.push_back({i, 1});
            count++;
        }
        return res;
    }
};