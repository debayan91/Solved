class Solution {
public:
    int minAddToMakeValid(string s) {
        int additions = 0;
        int count = 0;
        for(char c : s){
            if(c == '('){
                count++;
            }
            if(c == ')'){
                count--;
            }
            if(count < 0){
                additions += abs(count);
                count = 0;
            }
        }
        additions += count;
        return additions;
    }
};