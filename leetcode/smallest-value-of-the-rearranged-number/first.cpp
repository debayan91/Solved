class Solution {
public:
    long long smallestNumber(long long num) {
        int sign = num < 0 ? 1 : 0;
        if (num == 0) return 0;
        vector<int> a(10, 0);
        string s = "";
        if(sign) num = - num;
        while(num){
            a[num % 10]++;
            num /= 10;
        }
        if(sign){
            for(int i = size(a) - 1; i >= 0; i--){
                for(int j = 0; j < a[i]; j++){
                    s += to_string(i);
                }
            }
            num = stoll(s);
            return -num;
        } else {
            bool f = false;
            for(int i = 1; i < 10; i++){
                if(!f && a[i] > 0){
                    f = true;
                    for(int j = 0; j < 1; j++) s += to_string(i);
                    a[i]--;
                    for(int j = 0; j < a[0]; j++) s += '0';
                    for(int j = 0; j < a[i]; j++) s += to_string(i);
                } else for(int j = 0; j < a[i]; j++) s += to_string(i);
            }
            num = stoll(s);
            return num;
        }
    }
};