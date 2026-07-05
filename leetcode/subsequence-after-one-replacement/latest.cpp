class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int m = size(s);
        int n = size(t);
        if(m > n) return false;

        for(char c : t){
            int p = i;
            if(i < m && s[i] == c) i++;
            if(j < m && s[j] == c) j++;
            if(p < m) j = max(p + 1, j); //
            if(j == m) return true;
        }
        if(j == m) return true;
        return false;
        
    }
};