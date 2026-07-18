class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        for(int i = 0; i < size(s); i++){
            if(st.empty()) st.push({s[i], i});
            else if(s[i] == ')' && st.top().first == '(') st.pop();
            else st.push({s[i], i});
        }
        while(!st.empty()){
            s[st.top().second] = '*';
            st.pop();
        }
        int mx = 0;
        int count = 0;
        for(char c : s){
            if(c != '*') count++;
            else{
                mx = max(count, mx);
                count = 0;
            }
        }
        mx = max(count, mx);
        return mx;
    }
};