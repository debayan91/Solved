class Solution {
public:
    int lengthOfLastWord(string s) {
        while(size(s) && s.back() == ' ') s.pop_back();
        for(int i = size(s) - 1; i >= 0; i--){
            if(s[i] == ' ') return (size(s) - 1 - i);
        }
        return size(s);
    }
};