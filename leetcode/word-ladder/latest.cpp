class Solution {
public:
    int ladderLength(string a, string b, vector<string>& list) {
        if (find(list.begin(), list.end(), b) == list.end()) return 0;

        unordered_map<string, vector<string>> m;
        for (string& w : list) {
            for (int i = 0; i < w.size(); i++) {
                string temp = w;
                temp[i] = '*';
                m[temp].push_back(w); 
            }
        }
        
        queue<pair<string, int>> q; // word, distance

        q.push({a, 1});

        unordered_set<string> visited;
        visited.insert(a);

        while(!q.empty()){
            auto [word, dist] = q.front();
            q.pop();

            for(int i = 0; i < size(word); i++){
                string temp = word;
                temp[i] = '*';

                if(m.count(temp)){
                    // if the pattern exists
                    for(string& s : m[temp]){

                        if(s == b) return dist + 1;

                        if (visited.count(s) == 0) {
                            visited.insert(s);
                            q.push({s, dist + 1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};