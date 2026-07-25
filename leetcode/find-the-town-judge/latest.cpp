class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<bool> trusts_noone(n + 1, true);
        vector<int> v(n + 1, 0);
        for (auto& a : t) {
            trusts_noone[a[0]] = false;
            v[a[1]]++;
        }
        for (int i = 1; i < n + 1; i++)
            if (trusts_noone[i] && v[i] == n - 1){
                return i;
            }
        return -1;
    }
};