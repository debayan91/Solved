class Solution {
public:
    string removeDuplicates(string s) {
        int k = 2;
        stack<pair<char, int>> st;
        for(char c : s){
            if(st.empty()) st.push({c, 1});
            else {
                if(st.top().first == c){
                    st.push({c, st.top().second + 1});
                } else {
                    st.push({c, 1});
                }
            }
            if(st.top().second == k){
                for(int i = 0; i < k; i++) st.pop();
            }
        }
        s = "";
        while(!st.empty()){
            s = st.top().first + s;
            st.pop();
        }
        return s;
    }
};