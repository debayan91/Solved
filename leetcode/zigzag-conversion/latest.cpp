class Solution {
public:
    string convert(string s, int n) {
        vector<string> v(n);
        int index = 0;
        int i = 0; // max is numRows
        while(index < s.size()){
            while(index < s.size() && i < n){
                v[i++] += s[index++];
            }

            if(i > 2) i -= 2;
            else i = 0;

            while(index < s.size() && i >= 0){
                v[i--] += s[index++];
            }

            if(n == 1) i = 0;
            else i += 2;
        }
        string res = "";
        for(string a : v) res += a;
        return res;
    }
};