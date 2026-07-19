class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& t) {
        int i = start[0];
        int j = start[1];
        int x = t[0];
        int y = t[1];
        int a = (x + y) % 2;
        int b = (i + j) % 2;
        if(a == b) return 1;
        return 0;
    }
};