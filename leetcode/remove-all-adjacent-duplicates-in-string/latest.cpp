class Solution {
public:
    string removeDuplicates(string s) {
        int k = 2;
        stack<pair<char, int>> st;
        for(char c : s){
            if(st.empty()) st.push({c, 1});
            else {
                if(st.top().first == c){
                    st.top().second++;
                } else {
                    st.push({c, 1});
                }
            }
            if(st.top().second == k){
                st.pop();
            }
        }
        s = "";
        while(!st.empty()){
            string k(st.top().second, st.top().first);
            s += k;
            st.pop();
        }
        reverse(s.begin() ,end(s));
        return s;
    }
};