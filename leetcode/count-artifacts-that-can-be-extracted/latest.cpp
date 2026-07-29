class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int count = 0;
        unordered_set<string> st;
        for(auto& a : dig) st.insert(to_string(a[0]) + " " + to_string(a[1]));
        for(auto& a : artifacts){
            int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];
            bool b = 1;
            for(int i = r1; i <= r2 && b; i++){
                for(int j = c1; j <= c2 && b; j++){
                    if(!st.count(to_string(i) + " " + to_string(j))) b = 0;
                }
            }
            if(b) count++;
        }
        return count;
    }
};