class Solution {
public:
    bool isnum(string s) {
        try {
            size_t idx;
            int x = stoi(s, &idx);

            return idx == s.size() && x >= -200 && x <= 200;
        } catch (...) {
            return false;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (isnum(s))
                st.push(stoi(s));
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                string op = s;
                if (op == "+")
                    st.push(a + b);
                else if (op == "-")
                    st.push(b - a);
                else if (op == "*")
                    st.push(a * b);
                else if (op == "/")
                    st.push(b / a);
            }
        }
        return st.top();
    }
};