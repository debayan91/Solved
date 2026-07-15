class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> v(26, 0);
        for(char c : b) v[c - 'a']++;
        for(char c : a){
            v[c - 'a']--;
            if(v[c - 'a'] < 0) return false;
        }
        return true;
    }
};