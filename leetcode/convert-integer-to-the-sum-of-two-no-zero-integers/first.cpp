class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            string s1 = to_string(i), s2 = to_string(n - i);
            if(s1.find('0') == string::npos && s2.find('0') == string::npos){
                return {i, n - i};
            }
        }
        return {};
    }
};