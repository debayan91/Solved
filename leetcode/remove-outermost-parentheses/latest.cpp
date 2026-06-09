class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string res = "";
        int last = -1;
        int start = 0;
        while (last != size(s) - 1) {
            // remove the 1st borders
            for (int i = start; i < size(s); i++) {
                if (s[i] == '(') {
                    st.push(i);
                    if (i != start) {
                        res += s[i];
                    }
                } else {
                    if (st.top() == start) {
                        last = i;
                        st.pop();
                        break;
                    } else {
                        res += ')';
                        st.pop();
                    }
                }
                
                //cout << res << endl;
                
            }
            start = last + 1;
            while(!st.empty()) st.pop();
        }
        return res;
    }
};