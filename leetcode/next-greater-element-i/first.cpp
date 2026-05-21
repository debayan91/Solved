class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                int index = st.top();
                map[nums[index]] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        for(int i = 0; i < nums1.size(); i++){
            if(map.count(nums1[i]) == 0) nums1[i] = -1;
            else nums1[i] = map[nums1[i]];
        }
        return nums1;
    }
};