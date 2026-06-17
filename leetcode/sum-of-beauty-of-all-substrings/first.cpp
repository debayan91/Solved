class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<int> a(26, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            fill(a.begin(), a.end(), 0);
            int mx = 0;
           
            for (int j = i; j < n; j++) {
                int mn = 501;
                a[s[j] - 'a']++;
                mx = max(mx, a[s[j] - 'a']);
                for (int k : a){
                    if(k > 0 && k < mn){
                        mn = k;
                    }
                }
                sum += mx - mn;
            }
        }
        return sum;
    }
};