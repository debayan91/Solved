class Solution {
public:
    int minQueenMoves(vector<int>& s, vector<int>& t) {
        int sr = s[0], sc = s[1], r = t[0], c = t[1]; if(s == t) return 0; 
        if(sr == r || sc == c || abs(sc - c) == abs(sr - r)) return 1;
        return 2;
    }
};