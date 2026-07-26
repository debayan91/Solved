class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a,
                                            vector<vector<int>>& b) {
        vector<vector<int>> res;
        int i = 0, j = 0, k, p, q;
        int an = size(a), bn = size(b);
        while (i < an || j < bn) {
            if (i < an && j < bn)
                k = min(a[i][0], b[j][0]);
            else if (i < an)
                k = a[i][0];
            else
                k = b[j][0];
            if(i < an){
                p = a[i][1];
            } else p = 0;
            if(j < bn){
                q = b[j][1];
            } else q = 0;
            res.push_back({k, p + q});
            if(i < an && a[i][0] == k) i++;
            if(j < bn && b[j][0] == k) j++;
        }
        
        return res;
    }
};