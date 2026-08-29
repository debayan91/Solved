class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        if(s[0] == t[0] && s[1] == t[1]) return 0;
        if((s[0] + s[1]) % 2 != (t[0] + t[1]) % 2) return -1;
        return (abs(t[0] - s[0]) == abs(t[1] - s[1])) ? 1 : 2;
    }
};