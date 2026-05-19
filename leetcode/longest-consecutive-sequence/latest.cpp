class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> st;
        for(int i : nums) st.insert(i);
        for(int i : st){
            if(st.count(i - 1)) continue;
            int count = 1;
            int j = i + 1;
            if(st.count(j)){
                while(st.count(j)){
                    count++;
                    j++;
                }
            }
            mx = max(count, mx);
        }
        return mx;
    }
};