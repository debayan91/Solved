class Solution {
public:
    string rle(string a){
        int n = a.size();
        int i = 0;
        string res = "";
        while(i < n){
            char c = a[i];
            int count = 0;
            while(i < n && a[i] == c){
                count++;
                i++;
            }
            res += to_string(count) + c ;
        }
        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        for(int i = 0; i < n - 1; i++){
            // cout << res << endl;
            res = rle(res);
        }
        return res;
    }
};