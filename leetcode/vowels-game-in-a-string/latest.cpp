class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> st = {'a','e','i','o','u'};
        int sum = 0; for(char c : s) if(st.count(c)) return 1;
        return 0;
        
    }
};