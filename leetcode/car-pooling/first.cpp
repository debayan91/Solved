class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, vector<int>> m;
        int n = -1;
        for(auto& a : trips){
            m[a[1]].push_back(a[0]);
            m[a[2]].push_back(-a[0]);
            n = max(n, a[2]);
        }
        int k = 0;
        for(int i = 0; i < n; i++){
            if(m.count(i)){
                for(int a : m[i]){
                    k += a;
                }
                if(k > capacity) return false;
            }
        }
        return true;
    }
};