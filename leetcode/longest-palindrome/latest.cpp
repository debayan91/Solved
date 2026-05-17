class Solution {
public:
    int longestPalindrome(string s) {
        int array[129] = {0};

        for(char c : s){
            array[c]++;
        }

        int count = 0;
        int odd = 0;

        for(int a : array){
            if(a % 2 != 0 && odd == 0) odd = 1;
            count += (a / 2) * 2;
        }
        return count + odd;
    }
};