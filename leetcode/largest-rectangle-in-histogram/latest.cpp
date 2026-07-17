class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int mx = 0;
        heights.push_back(0);
        for(int i = 0; i < size(heights); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                int left_boundary = st.empty() ? -1 : st.top(); 
                int width = i - left_boundary - 1; // right bouondary - left boundary + 1
                int area = width * h;
                mx = max(mx, area);
            }
            st.push(i);
        }
        return mx;
    }
};