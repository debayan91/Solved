class Solution {
public:
    void comp(vector<int>& baseTime, vector<vector<int>>& list, int current, vector<long long>& fin){
        if(fin[current] > 0){
            return;
        }
        if(list[current].size() == 0){
            fin[current] = baseTime[current];
            return;
        }
        /////////
        if(fin[current] > 0){
            return;
        }
        ////////
        for(int node : list[current]){
            comp(baseTime, list, node, fin);
        }
        /////////
        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;
        for(int node : list[current]){
            // mn = min(mn, fin[node]);
            // mx = max(mx, fin[node]);
            if(fin[node] < mn) mn = fin[node];
            if(fin[node] >mx) mx = fin[node];
        }
        fin[current] =  (mx - mn) + baseTime[current];
        fin[current] += mx;
        
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<long long> fin(n, -1);
        vector<vector<int>> list(n);
        for(auto& a : edges){
            list[a[0]].push_back(a[1]);
        }
        comp(baseTime, list, 0, fin);
        return fin[0];
    }
};