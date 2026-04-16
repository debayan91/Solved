class Solution {
public:
    bool isPalindrome(string s) {
        string v = "";
        for(char c:s){
            if(isalnum(c)){
                v.push_back(tolower(c));
            }
        }
        string a = v;
        reverse(v.begin(),v.end());
        if(v == a) return true;
        return false;
    }
};