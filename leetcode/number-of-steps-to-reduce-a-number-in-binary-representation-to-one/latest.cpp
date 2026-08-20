class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while(s != "1"){
            count++;
            int n = size(s);
            if(s[n - 1] == '1'){
                s[n - 1] = '0';
                int carry = 1;
                for(int i = n - 2; i >= 0; i--){
                    if(s[i] == '0'){
                        s[i] = '1';
                        carry = 0;
                        break;
                    } else {
                        s[i] = '0';
                    }
                }
                if(carry){
                    s = "1" + s;
                }
            } else {
                s.pop_back();
            }
        }
        return count;
    }
};