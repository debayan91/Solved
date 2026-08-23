class Solution {
public:
    bool isPalindromic(string s) {
        string res = "";
        for(char c : s){
            bitset<8> bb(c);
            res += bb.to_string();
        }
        string k = res; reverse(begin(k), end(k));
        return k == res;
    }
};