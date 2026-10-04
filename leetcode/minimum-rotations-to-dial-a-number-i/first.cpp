class Solution {
public:
    int minRotations(string s) {
        int current = 0, count = 0;
        for(auto c : s){
            int t = c - '0'; count += min(abs(t - current), 10 - abs(t - current));
            current = t;
        }
        return count;
    }
};