
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<array<int, 2>>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int k = 0;
        vector<int> comp(n, -1), w(n, -1);

        for(int i = 0; i < n; i++){
            if(comp[i] != -1) continue;

            stack<int> st;
            st.push(i);
            comp[i] = k;
            w[k] = -1; 

            while(!st.empty()){
                int current = st.top();
                st.pop();

                for(auto ne : adj[current]){
                    w[k] &= ne[1];

                    if(comp[ne[0]] == -1){
                        comp[ne[0]] = k;
                        st.push(ne[0]);
                    }
                }
            }
            k++;
        }

        vector<int> res;

        for(auto& a : q){
            if(comp[a[0]] != comp[a[1]]){
                res.push_back(-1);
            } else if(a[0] == a[1]){
                res.push_back(0);
            } else {
                res.push_back(w[comp[a[0]]]);
            }
        }

        return res;
    }
};
