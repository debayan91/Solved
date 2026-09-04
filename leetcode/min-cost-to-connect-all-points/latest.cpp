class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {


        auto dis = [](const std::vector<int>& p1, const std::vector<int>& p2) {
            return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
        };


        int cost = 0, n = size(points);


        vector<bool> vis(n, false);


        vector<int> mindist(n, INT_MAX);


        mindist[0] = 0;


        for(int c = 0; c < n; c++){


            int next = -1;

            
            for (int i = 0; i < n; i++) { // find the one with the lowest mindist & unvisited
                if (!vis[i] && (next == -1 || mindist[i] < mindist[next])) {
                    next = i;
                }
            }

            vis[next] = 1; // add it
            cost += mindist[next];


            for (int v = 0; v < n; v++) { // from the newly added point can i reach any other point faster?
                if (!vis[v]) {
                    int d = dis(points[next], points[v]);
                    mindist[v] = min(mindist[v], d);
                }
            }


        }
        return cost;
    }
};