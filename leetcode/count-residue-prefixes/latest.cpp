class Solution {
public:
    int residuePrefixes(string s) {
        int n = size(s), i = 1, res = 0;
        set<char> st;
        for(char c : s){
            st.insert(c); 
            if(st.size() == i++ % 3) res++;
        }
        return res;
    }
};