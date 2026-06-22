class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp = {
            {'b', 0},
            {'a', 0},
            {'l', 0},
            {'o', 0},
            {'n', 0}
        };
        for(char c : text){
            if(mp.count(c)){
                mp[c]++;
            }
        }
        int count = INT_MAX;
        for(auto& [key, value] : mp){
            if(key == 'l' || key == 'o') value /= 2;
            count = min(count, value);
        }
        return count;
    }
};