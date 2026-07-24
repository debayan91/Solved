class Solution {
public:
    string largestGoodInteger(string num) {
        string mx = "///";
        for(int i = 0 ; i < size(num) - 3 + 1; i++){
            string s = num.substr(i, 3);
            bool a = 1;
            for(char c : s) if(c != s[0]) a = 0;
            if(a) mx = max(mx, s);
        }
        return mx == "///" ? "" : mx;
    }
};