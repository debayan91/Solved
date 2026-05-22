class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int count = 0;
        int index = 0;
        while (i < chars.size()) {
            int current = 1;
            char c = chars[i];
            while (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
                current++;
                i++;
            }
            cout << current << endl;
            if (current == 1) {
                chars[index++] = c;
                i++;
            } else {
                chars[index++] = c;
                string s = to_string(current);
                int k = 0;
                while (k < s.size())
                    chars[index++] = s[k++];
                i++;
            }
        }
        while (index < chars.size())
            chars.pop_back();
        return chars.size();
    }
};