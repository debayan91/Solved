class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(mp.count(c)){
                if(islower(c)){
                    mp[c] = max(i, mp[c]); // last lowercase
                }
                if(isupper(c)){
                    mp[c] = min(i, mp[c]); // first uppercase
                }
            }
            else{
                mp[c] = i;
            }
        }
        int count = 0;
        for(auto& [ch, index] : mp){
            if(islower(ch)){
                char upper = toupper(ch);
                if(mp.count(upper) && mp[upper] > index){
                    count++;
                }
            }
        }
        return count;
    }
};