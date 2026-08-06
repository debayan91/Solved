class Solution {
public:
    bool works(string a, string b){
        int changes = 0, i = 0, j = 0;
        while(i < size(a)){
            if(a[i] == b[j]){
                j++;
            } else {
                changes++;
            }
            i++;
        }
        return changes == 1;
    }
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [&](auto& a, auto& b){
            return size(a) < size(b);
        });
        int n = size(words);
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(size(words[j]) + 1 == size(words[i]) && works(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};