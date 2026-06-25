class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v(26, 0);
        int count = 0;
        for(char c : chars) v[c - 'a']++;
        for(string s : words){
            vector<int> vv = v;
            bool flag = true;
            for(char c : s){
                vv[c - 'a']--;
                if(vv[c - 'a'] < 0){
                    flag = false;
                    break;
                }
            }
            if(flag) count += size(s);
        }
        return count;
    }
};