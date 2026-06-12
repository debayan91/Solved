class Solution {
public:
    string removeStars(string s) {
        string res = "";
        int skip = INT_MAX;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '*'){
                if(skip == INT_MAX){
                    skip = i - 1;
                    while(skip >= 0 && s[skip] == '*'){
                        skip--;
                    }
                }else{
                    if(skip > i) skip = i - 1;
                    else skip--;
                    while(skip >= 0 && s[skip] == '*'){
                        skip--;
                    }
                }
            }else{
                if(i < skip){
                    res += s[i];
                }else{
                    continue;
                }
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};