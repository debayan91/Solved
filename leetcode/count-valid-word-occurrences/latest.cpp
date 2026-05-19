class Solution {
public:
    bool isvalid(string& s, int& i) {
        if (
            i < s.size() && (
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] == '-' && i - 1 >= 0 && i + 1 < s.size() && (s[i - 1] >= 'a' && s[i - 1] <= 'z') && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
            )) return true;
            else return false;
    }
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        string s = "";
        for (string a : chunks)
            s += a;
        unordered_map<string, int> words;
        int i = 0;
        while (i < s.size()) {
            int start = -1;
            int end = -1;
            while(!isvalid(s, i) && i < s.size()) i++;
            if(isvalid(s, i)) start = i;
            while(isvalid(s, i) && i < s.size()) i++;
            end = i == start ? start : i - 1;
           if(start != -1 && end != -1) words[(s.substr(start, end - start + 1))]++;
        }
        vector<int> res;
        for(int i = 0; i < queries.size(); i++){
            if(words.count(queries[i]) != 0) res.push_back(words[queries[i]]);
            else(res.push_back(0));
        }
        return res;
    }
};