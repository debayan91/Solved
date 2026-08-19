class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int l = 0, r = 0, res = 0, n = size(s);
        while(r < n){
            m[s[r]]++;
            if(m.size() == 3){
                int a = n - r - 1, b = 0;
                while(l < r && m[s[l]] > 1){
                    m[s[l]]--;
                    l++;
                    b++;
                }
                res += (a + 1) * (b + 1);
                m.erase(s[l++]);
            }
            r++;
        }
        return res;
    }
};

