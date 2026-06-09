class Solution {
public:
    string largestOddNumber(string num) {
        while(size(num) > 0 && (num.back() - '0') % 2 == 0) num.pop_back();
        return num;
    }
};