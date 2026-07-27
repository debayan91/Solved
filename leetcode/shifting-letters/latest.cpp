class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = size(shifts);
        unsigned long int sum = accumulate(begin(shifts), end(shifts), 0LL);
        for(int i = 0; i < n; i++){
            unsigned long int sh = (sum + s[i] - 'a') % 26;
            s[i] = 'a' + sh;
            sum -= shifts[i];
        }
        return s;
    }
};