class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int count = 0;
        for(char c : s){
            if(c == '('){
                count++;
            }
            if(c == ')'){
                count--;
            }
            mx = max(count, mx);
        }
        return mx;
    }
};