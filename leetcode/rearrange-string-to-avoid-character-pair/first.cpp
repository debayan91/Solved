class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string res = "";
        for(char c : s) if(c == y) res += c;
        for(char c : s) if(c != y && c != x) res += c;
        for(char c : s) if(c == x) res += c;
        return res;
    }
};