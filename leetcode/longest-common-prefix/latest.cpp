class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool flag = true;
        string res = "";
        int index = 0;
        while(flag){
            char current = strs[0][index];
            if(current == '\0') break;
            for(int i = 1;i<strs.size();i++){
                if(strs[i][index] != current) flag = false;
            }
            if(flag) res += current;
            index++;
        }
        return res;
    }
};