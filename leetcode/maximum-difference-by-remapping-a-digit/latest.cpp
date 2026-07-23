class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int i = 0;
        char c;
        while(i < size(s) && s[i] == '9') i++;
        if(i == size(s)){
            
        } else {
            c = s[i];
            for(char& cc : s) if(cc == c) cc = '9';
        }
        int a = stoi(s);
        s = to_string(num);
        c = s[0];
        for(char& cc : s) if(cc == c) cc = '0';
        int b = stoi(s);
        return a - b;
    }
};