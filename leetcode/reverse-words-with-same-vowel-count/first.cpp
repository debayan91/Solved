class Solution {
public:
    int c(const std::string& str) {
        const std::string vowels = "aeiou";

        return std::count_if(str.begin(), str.end(), [&vowels](char ch) {
            return vowels.find(ch) != std::string::npos;
        });
    }
    string reverseWords(string text) {
        std::stringstream ss(text);
        std::string word;
        std::vector<std::string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        int k = c(words[0]);
        string res = "";
        res += words[0];
        for(int i = 1; i < size(words); i++){
            if(c(words[i]) == k){
                reverse(begin(words[i]), end(words[i]));
            }
            res += " " + words[i];
        }
        return res;
    }
};