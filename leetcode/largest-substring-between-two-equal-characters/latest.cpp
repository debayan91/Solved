class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int i = 0;
        int j = size(s) - 1;
        int mx = -1;
        for(int i = 0; i <= j; i++){
            int a = s[i];
            int k = j;
            while(s[k] != a) k--;
            mx = max(mx, k - i - 1);
        }
        return mx;
    }
};