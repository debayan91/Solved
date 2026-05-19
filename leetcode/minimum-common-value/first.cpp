class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int i : nums1) st.insert(i);
        long long min = INT_MAX;
        for(int i : nums2){
            if(st.count(i) != 0){
                if(i < min) min = i;
            }
        }
        cout << INT_MIN << endl << INT_MAX;
        if(min == INT_MIN || min == INT_MAX) return -1;
        return (int) min;
    }
};