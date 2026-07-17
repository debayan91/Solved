class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        
        int i = 0, j = 0;
        string p = to_string(i) + " " + to_string(j);
        st.insert(p);
        for(char c : path){
            if(c == 'N'){
                i--;
            }
            if(c == 'S'){
                i++;
            }
            if(c == 'E'){
                j++;
            }
            if(c == 'W'){
                j--;
            }
            string p = to_string(i) + " " + to_string(j);
            if(st.count(p)) return true;
            st.insert(p);
        }
        return false;
    }
};