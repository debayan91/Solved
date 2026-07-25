class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<bool> trusts_noone(n + 1, true);
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
        for (auto a : t) {
            v[a[0]][a[1]] = 1;
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (v[i][j] && i != j) trusts_noone[i] = false;
            }
        }
        for (int i = 1; i < n + 1; i++)
            if (trusts_noone[i]){
                bool flag = true;
                for(int j = 1; j < n + 1; j++){
                    if(i != j && v[j][i] == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag) return i;
            }
        return -1;
    }
};