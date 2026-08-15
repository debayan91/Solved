class Solution {
public:
    int elevatorRequests(int f, vector<int>& r) {
        int n = size(r), res = 0, current = 0;
        for(int i = 0; i < n; i++){
            res += abs(r[i] - current);
            current = r[i];
        }
        return res;
    }
};