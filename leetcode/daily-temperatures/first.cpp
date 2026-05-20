class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            //monotonic stack
            while(!st.empty() && nums[i] > nums[st.top()]){
                int index = st.top();
                st.pop();
                res[index] = i - index;
            }
            st.push(i);
        }
        return res;
    }
};