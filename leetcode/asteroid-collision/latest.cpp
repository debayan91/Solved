class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i : asteroids) {
            if (i > 0) {
                st.push(i);
            } else {
                if (st.empty()) {
                    st.push(i);
                } else {
                    if (st.top() > abs(i)) {

                    } else if (st.top() < 0) {
                        st.push(i);
                    } else {
                        if (st.top() == abs(i)) {
                            st.pop();
                        } else {
                            while (!st.empty() && st.top() > 0 &&
                                   st.top() < abs(i)) {
                                st.pop();
                            }
                            if (!st.empty() && st.top() == abs(i)) {
                                st.pop(); // both destroyed
                            }
                            else if (!st.empty() && st.top() > abs(i)) {

                            } else {
                                st.push(i);
                            }
                        }
                    }
                }
            }
        }
        vector<int> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(begin(v), end(v));
        return v;
    }
};