class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(routes); i++) {
            for (int r : routes[i]) {
                adj[r].push_back(i);
            }
        }
        queue<int> q;
        q.push(source);
        unordered_set<int> v; // visited for stops
        v.insert(source);
        vector<bool> vb(size(routes), false); // visited for buses
        int count = 0;
        while(!q.empty()){ // the queue stores stops
            int size = q.size();
            count++; // whenever i'm here, its a stop i havent been to before
            while(size--){
                int stop = q.front();
                q.pop();
                for(int b : adj[stop]){
                    if(vb[b]) continue; // if the bus is visited
                    vb[b] = true; // board the bus
                    for(int st : routes[b]){ // for all the stops this bus can go to
                        if(st == target) return count;
                        if(v.count(st) == 0){
                            v.insert(st);
                            q.push(st);
                            // this way every route and bus is explored only once
                        }
                    }
                }
            }
        }
        return -1;
    }
};