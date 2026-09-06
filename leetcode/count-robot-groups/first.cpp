class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int d) {

        int n = size(position);

        if (n == 1)
            return 1;

        // d doesnt matter

        vector<pair<int, int>> groups;

        for (int i = 0; i < n; i++) {
            if (!groups.empty() && position[i] - groups.back().first <= d) {
                groups.back().first = position[i];
                groups.back().second = speed[i];
            } else {
                groups.push_back({position[i], speed[i]});
            }
        }

        //mts 

        vector<pair<int, int>> st;

        for(auto [p, s] : groups){
            while(!st.empty() && st.back().second > s){
                st.pop_back();
            }
            st.push_back({p, s});
        }

        return size(st);
    }
};