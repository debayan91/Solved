class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int mx = INT_MIN;
        for(string a : strs){
            bool f = false;
            for(char c : a){
                if(!isdigit(c)){
                    int s = size(a);
                    mx = max(mx, s);
                    f = true;
                    break;
                }
            }
            if(!f) mx = max(stoi(a), mx);
        }
        return mx;
    }
};