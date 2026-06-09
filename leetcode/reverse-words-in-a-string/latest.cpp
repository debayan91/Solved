class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int i = 0;
        string current = "";
        while (i < size(s)) {
            while (i < size(s) && s[i] == ' ')
                i++;
            if (s[i] != ' ') {
                current = "";
                bool flag = false;
                while (i < size(s) && s[i] != ' ') {
                    current += s[i++];
                    flag = true;
                }
                if(flag) v.push_back(current);
            }
        }
        current = "";
        for (int i = size(v) - 1; i >= 0; i--) {
           //cout << "+" << v[i] << "+" << " ";
            if(i != 0) current += v[i] +  " ";
            else current += v[i];
        }
        return current;
    }
};