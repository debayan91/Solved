class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int mx = 0;
        int n = size(s);
        int i = 0;
        while(i < n){
            while(i < n && s[i] == '1') i++;
            int zeros = 0;
            while(i < n && s[i] == '0'){
                i++;
                zeros++;
            }
            int ones = 0;
            while(i < n && s[i] == '1'){
                i++;
                ones++;
            }
            int x = min(ones, zeros);
            mx = max(x * 2, mx);
        }
        return mx;
    }
};