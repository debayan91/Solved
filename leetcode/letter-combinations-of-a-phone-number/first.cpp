class Solution {
public:
    vector<vector<char>> mp = {
        {},                   // 0
        {},                   // 1
        {'a', 'b', 'c'},      // 2
        {'d', 'e', 'f'},      // 3
        {'g', 'h', 'i'},      // 4
        {'j', 'k', 'l'},      // 5
        {'m', 'n', 'o'},      // 6
        {'p', 'q', 'r', 's'}, // 7
        {'t', 'u', 'v'},      // 8
        {'w', 'x', 'y', 'z'}  // 9
    };
    vector<string> res;
    void backtrack(string current, int index, string digits){
        if(current.size() == digits.size()){
            res.push_back(current);
            return;
        }
        int number = digits[index] - '0';
        index++;
        for(int i = 0; i < mp[number].size(); i++){
            current += mp[number][i];
            backtrack(current, index, digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        backtrack("", 0, digits);
        return res;
    }
};