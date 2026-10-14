class Solution {
public:
    long long countPairs(vector<string>& words) {
        for(auto& s : words){
            int k = 'z' - s[0];
            for(char& c : s){
                c = 'a' + (((c - 'a') + k) % 26);
            }
            cout << s << " ";
        }
        map<string, int> m;
        for(int i = 0; i < size(words); i++){
            m[words[i]]++;
        }
        long long res = 0;
        for(auto& [a, b] : m){
            res += 1LL * b * (long long)(b - 1) / 2LL;
        }
        return res;
    }
};