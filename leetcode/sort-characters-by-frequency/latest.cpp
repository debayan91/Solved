class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> f(256);
        for(int i = 0; i < 256; i++) f[i] = {(char)i, 0};
        for(char c : s) f[(int)c].second++;
        sort(begin(f), end(f), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;
        });
        int index = 0;
        for(auto a : f){
            if(a.second == 0) break;
            for(int i = 0; i < a.second; i++){
                s[index++] = a.first;
            }
        }
        return s;
    }
};