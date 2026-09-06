class Solution {
public:
    int countRotations(string s, int k) {
        int n = size(s);
        // string t = s + s;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == s[(i + 1) % n]) count++;
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            int last = i - 1;
            if(last == -1) last = n - 1;
            int score = count - (s[last] == s[i] ? 1 : 0);
            if(score == k) res++;
        }
        return res;
    }
};