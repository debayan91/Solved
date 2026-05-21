class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums1 = nums;
        nums.insert(nums.end(), nums.begin(), nums.end());

        int n = nums.size();
        unordered_map<int, int> map;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                int index = st.top();

                if(map.count(index) == 0) map[index] = nums[i];

                st.pop();
            }
            st.push(i);
        }

        for(int i = 0; i < nums1.size(); i++){
            if(map.count(i) == 0) nums1[i] = -1;
            else nums1[i] = map[i];
        }

        return nums1;
    }
};