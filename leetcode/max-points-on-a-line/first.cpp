class Solution {
public:
    bool sameLine(int x1, int y1, int x2, int y2, int x3, int y3) {
        return (long long)(y2 - y1) * (x3 - x1) == (long long)(y3 - y1) * (x2 - x1);
    }
    int maxPoints(vector<vector<int>>& p) {
        if(size(p) == 1) return 1;
        int n = size(p);
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = p[i][0], x2 = p[j][0], y1 = p[i][1], y2 = p[j][1];
                int count = 2;
                for(auto& pp : p){
                    if(pp == p[i] || pp == p[j]) continue;
                    if(sameLine(x1, y1, x2, y2, pp[0], pp[1])) count++;
                }
                mx = max(mx, count);
            }
        }
        return mx;
    }
};