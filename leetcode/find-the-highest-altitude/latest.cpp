class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int mx = 0;
        for(int i : gain){
            alt += i;
            mx = max(alt, mx);
        }
        return mx;
    }
};