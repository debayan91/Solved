class Solution {
   public:
    int openLock(vector<string>& d, string target) {
        unordered_set<string> st(begin(d), end(d));
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> explored;
        explored.insert("0000");
        if(st.count("0000")) return -1;
        while(!q.empty()){
            auto [current, t] = q.front();
            q.pop();
            if(current == target) return t;
            for(int i = 0; i < 4; i++){
                //if(current[i] == target[i]) continue;
                char c = current[i];
                current[i] = '0' + ((c - '0' + 1) % 10);
                if(st.count(current) == 0 && !explored.count(current)){
                    q.push({current, t + 1});
                    explored.insert(current);

                }
                if(c == '0') current[i] = '9';
                else current[i] = '0' + ((c - '0' - 1) % 10);
                if(st.count(current) == 0 && !explored.count(current)){
                    q.push({current, t + 1});
                    explored.insert(current);

                }
                current[i] = c;
            }
        }
        return -1;
    }
};