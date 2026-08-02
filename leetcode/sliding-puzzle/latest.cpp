class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (auto& row : board)
            for (int x : row)
                start += x + '0';
        string target = "123450";
        vector<vector<int>> adj = {
            {1, 3},    // 0
            {0, 2, 4}, // 1
            {1, 5},    // 2
            {0, 4},    // 3
            {1, 3, 5}, // 4
            {2, 4}     // 5
        };
        queue<string> q;           // bfs
        unordered_set<string> vis; // visited state
        q.push(start);
        vis.insert(start);
        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                q.pop();
                if (cur == target)
                    return moves;
                int zero = cur.find('0');
                for (int nxt : adj[zero]) {
                    string temp = cur;
                    swap(temp[zero], temp[nxt]);
                    if (!vis.count(temp)) {
                        vis.insert(temp);
                        q.push(temp);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};