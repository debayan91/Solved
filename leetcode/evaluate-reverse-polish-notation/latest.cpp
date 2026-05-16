class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (!((s.size() == 1) && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')))
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