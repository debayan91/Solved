class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for(char c : s) a[c - 'a']++;
        for(char c : t) a[c - 'a']--;
        for(int i : a) if(i != 0) return false;
        return true;
    }
};